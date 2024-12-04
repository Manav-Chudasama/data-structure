#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;
struct Node *createList(struct Node *);
struct Node *display(struct Node *);
struct Node *insertBeg(struct Node *);
struct Node *insertAfter(struct Node *);
struct Node *insertEnd(struct Node *);
struct Node *deleteBeg(struct Node *);
struct Node *deleteEnd(struct Node *);

void main()
{
    int choice;

    while (1)
    {
        printf("\n1. Create List \n2. display \n3. Insert At begining \n4. Insert at End \n5. delete at begining \n6. delete at End \n7. Exit \n8. insert after a given node.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = createList(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            start = insertBeg(start);
            break;
        case 4:
            start = insertEnd(start);
            break;
        case 5:
            start = deleteBeg(start);
            break;
        case 6:
            start = deleteEnd(start);
            break;
        case 7:
            exit(0);
            break;
        case 8:
            start = insertAfter(start);
            break;
        default:
            printf("\nEnter a valid choice");
            break;
        }
    }
}

struct Node *createList(struct Node *start)
{
    int num;

    printf("\nEnter the data for node or -1 to exit: ");
    scanf("%d", &num);

    while (num != -1)
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = num;

        if (start == NULL)
        {
            new_node->next = new_node;
            start = new_node;
        }
        else
        {
            struct Node *ptr = start;

            while (ptr->next != start)
            {
                ptr = ptr->next;
            }

            ptr->next = new_node;
            new_node->next = start;
        }

        printf("\nEnter the data for node or -1 to exit: ");
        scanf("%d", &num);
    }
    return start;
}
struct Node *display(struct Node *start)
{
    struct Node *ptr;
    ptr = start;

    if (start == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nNode: ");
        while (ptr->next != start)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d", ptr->data);
    }
}
struct Node *insertBeg(struct Node *start)
{
    struct Node *new_node, *ptr;
    ptr = start;
    int num;

    printf("\nEnter the data: ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    while (ptr->next != start)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
    new_node->next = start;
    start = new_node;

    return start;
}
struct Node *insertEnd(struct Node *start)
{
    struct Node *new_node, *ptr;
    int num;
    ptr = start;

    printf("\nEnter the data: ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;
    new_node->next = start;

    while (ptr->next != start)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;

    return start;
}
struct Node *deleteBeg(struct Node *start)
{
    struct Node *ptr;
    ptr = start;

    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = start->next;
    free(start);
    start = ptr->next;

    return start;
}
struct Node *deleteEnd(struct Node *start)
{
    struct Node *ptr, *preptr;
    ptr = start;

    while (ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = start;

    free(ptr);

    return start;
}
struct Node *insertAfter(struct Node *start)
{
    struct Node *new_node, *ptr, *preptr;
    int num, val;
    ptr = start->next;
    preptr = start;

    printf("\nEnter the data of the node after which new is to be inserted: ");
    scanf("%d", &val);

    printf("\nEnter the data for new node: ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = new_node;
    new_node->next = ptr;

    return start;
}