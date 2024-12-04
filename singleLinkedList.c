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
struct Node *insertAtBeg(struct Node *);
struct Node *insertAtEnd(struct Node *);
struct Node *insertBefore(struct Node *);
struct Node *insertAfter(struct Node *);
struct Node *deleteAtBeg(struct Node *);
struct Node *deleteAtEnd(struct Node *);
struct Node *deleteNode(struct Node *);
struct Node *deleteAfter(struct Node *);

void main()
{
    int choice;

    while (1)
    {
        printf("\n1. Create a List.");
        printf("\n2. display the List.");
        printf("\n3. Insert At the Beggining of the List.");
        printf("\n4. Insert At the End of the List.");
        printf("\n5. Insert before a given node in a List.");
        printf("\n6. Insert After a given node in a List.");
        printf("\n7. Delete At the Beggining of the List.");
        printf("\n8. Delete At the End of the List.");
        printf("\n9. Delete The given node in a List.");
        printf("\n10. Delete After a given node in a List.");
        printf("\n11. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = createList(start);
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insertAtBeg(start);
            break;
        case 4:
            start = insertAtEnd(start);
            break;
        case 5:
            start = insertBefore(start);
            break;
        case 6:
            start = insertAfter(start);
            break;
        case 7:
            start = deleteAtBeg(start);
            break;
        case 8:
            start = deleteAtEnd(start);
            break;
        case 9:
            start = deleteNode(start);
            break;
        case 10:
            start = deleteAfter(start);
            break;
        case 11:
            exit(0);
            break;
        default:
            printf("\nEnter a valid option.");
            break;
        }
    }
}

struct Node *createList(struct Node *start)
{
    struct Node *new_node, *ptr;
    int num;

    printf("\nEnter your data or -1 to end: ");
    scanf("%d", &num);

    while (num != -1)
    {
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = num;

        if (start == NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }

        printf("\nEnter your data or -1 to end: ");
        scanf("%d", &num);
    }

    return start;
}

struct Node *display(struct Node *start)
{
    struct Node *ptr = start;
    if (start == NULL)
    {
        printf("\nUnderflow!");
    }
    else
    {
        printf("\nNodes: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }

    return start;
}

struct Node *insertAtBeg(struct Node *start)
{
    struct Node *new_node;
    int num;

    printf("\nEnter the data: ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    new_node->next = start;
    start = new_node;

    return start;
}

struct Node *insertAtEnd(struct Node *start)
{
    struct Node *new_node, *ptr;
    int num;
    ptr = start;

    printf("\nEnter the data: ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;
    new_node->next = NULL;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;

    return start;
}

struct Node *insertBefore(struct Node *start)
{
    struct Node *new_node, *ptr, *preptr;
    int num, val;
    ptr = start;

    printf("\nEnter the data of node to be inserted: ");
    scanf("%d", &num);

    printf("\nEnter the data of node before which the new node is to be inserted: ");
    scanf("%d", &val);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    while (ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = new_node;
    new_node->next = ptr;

    return start;
}

struct Node *insertAfter(struct Node *start)
{
    struct Node *new_node, *ptr, *preptr;
    int num, val;
    ptr = start;
    preptr = ptr;

    printf("\nEnter the data of Node to be inserted: ");
    scanf("%d", &num);

    printf("\nEnter the data of node after which the new node is to be inserted: ");
    scanf("%d", &val);

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

struct Node *deleteAtBeg(struct Node *start)
{
    struct Node *ptr;

    ptr = start;
    start = start->next;

    free(ptr);

    return start;
}

struct Node *deleteAtEnd(struct Node *start)
{
    struct Node *ptr, *preptr;
    ptr = start;

    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;
    free(ptr);

    return start;
}

struct Node *deleteNode(struct Node *start)
{
    struct Node *ptr, *preptr;
    ptr = start;
    int val;

    printf("\nEnter the node to be deleted: ");
    scanf("%d", &val);

    while (ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = ptr->next;
    free(ptr);

    return start;
}

struct Node *deleteAfter(struct Node *start)
{
    struct Node *ptr, *preptr;
    int val;
    ptr = start;
    preptr = ptr;

    printf("\nEnter the data of the node After which the node is to be deleted: ");
    scanf("%d", &val);

    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = ptr->next;
    free(ptr);

    return start;
}