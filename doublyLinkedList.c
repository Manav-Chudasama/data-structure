#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *start = NULL;
struct Node *createList(struct Node *);
struct Node *display(struct Node *);
struct Node *insertBeg(struct Node *);
struct Node *insertEnd(struct Node *);
struct Node *insertBefore(struct Node *);
struct Node *insertAfter(struct Node *);
struct Node *delete_beg(struct Node *);
struct Node *delete_end(struct Node *);
struct Node *delete_before(struct Node *);
struct Node *delete_after(struct Node *);

void main()
{
    int choice;

    while (1)
    {
        printf("\n1. Create List");
        printf("\n2. display List");
        printf("\n3. insert a node at begining of the List");
        printf("\n4. insert a node at End of the List");
        printf("\n5. insert before a given node in a List");
        printf("\n6. insert After a given node in a List");
        printf("\n7: Delete a node from the beginning");
        printf("\n8: Delete a node from the end");
        printf("\n9: Delete a node before a given node");
        printf("\n10: Delete a node after a given node");
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
            start = insertBefore(start);
            break;
        case 6:
            start = insertAfter(start);
            break;
        case 7:
            start = delete_beg(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            start = delete_before(start);
            break;
        case 10:
            start = delete_after(start);
            break;
        default:
            exit(0);
            break;
        }
    }
}

struct Node *createList(struct Node *start)
{
    int num;
    printf("\nEnter node data or -1 tp exit: ");
    scanf("%d", &num);

    while (num != -1)
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = num;

        if (start == NULL)
        {
            new_node->next = NULL;
            new_node->prev = NULL;
            start = new_node;
        }
        else
        {
            struct Node *ptr;
            ptr = start;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }

        printf("\nEnter node data or -1 tp exit: ");
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
        printf("\nNodes: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}
struct Node *insertBeg(struct Node *start)
{
    struct Node *new_node;
    int num;

    printf("\nEnter the data of new node: ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;
    new_node->prev = NULL;
    new_node->next = start;
    start->prev = new_node;
    start = new_node;

    return start;
}
struct Node *insertEnd(struct Node *start)
{
    struct Node *new_node, *ptr;
    int num;
    ptr = start;

    printf("\nEnter the data for node: ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;

    return start;
}
struct Node *insertBefore(struct Node *start)
{
    struct Node *new_node, *ptr;
    int num, val;
    ptr = start;

    printf("\nEnter the value of node before which new node is to be inserted: ");
    scanf("%d", &val);

    printf("\nEnter the data for the node to be inserted: ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    while (ptr->data != val)
    {
        ptr = ptr->next;
    }

    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;

    return start;
}
struct Node *insertAfter(struct Node *start)
{
    struct Node *new_node, *ptr;
    int num, val;
    ptr = start;

    printf("\nEnter the value of node After which new node is to be inserted: ");
    scanf("%d", &val);

    printf("\nEnter the data for the node to be inserted: ");
    scanf("%d", &num);

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;

    while (ptr->data != val)
    {
        ptr = ptr->next;
    }

    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;

    return start;
}
struct Node *delete_beg(struct Node *start)
{
    struct Node *ptr;
    ptr = start;

    start = start->next;
    start->prev = NULL;

    free(ptr);

    return start;
}
struct Node *delete_end(struct Node *start)
{
    struct Node *ptr;
    ptr = start;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->prev->next = NULL;

    free(ptr);

    return start;
}
struct Node *delete_before(struct Node *start)
{
    struct Node *ptr, *temp;
    int val;
    ptr = start;

    printf("\nEnter the value of node before which new node is to be inserted: ");
    scanf("%d", &val);

    while (ptr->data != val)
    {
        ptr = ptr->next;
    }

    temp = ptr->prev;

    ptr->prev = temp->prev;
    temp->prev->next = ptr;

    free(temp);

    return start;
}
struct Node *delete_after(struct Node *start)
{
    struct Node *ptr, *temp;
    int val;
    ptr = start;

    printf("\nEnter the value of node After which new node is to be inserted: ");
    scanf("%d", &val);

    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;

    ptr->next = temp->next;
    temp->next->prev = ptr;

    free(temp);

    return start;
}