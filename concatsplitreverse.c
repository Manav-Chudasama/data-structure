#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;
struct Node *list1 = NULL;
struct Node *list2 = NULL;
struct Node *first = NULL;
struct Node *second = NULL;
struct Node *createList(struct Node *);
void display(struct Node *);
struct Node *concat(struct Node *, struct Node *);
void split(struct Node *, int, struct Node **, struct Node **);
struct Node *reverse(struct Node *);
struct Node *copy(struct Node *);

void main()
{
    int choice;
    int pos;

    while (1)
    {
        printf("\n1. Create a List1.");
        printf("\n2. Create a List2.");
        printf("\n3. display the List.");
        printf("\n4. concat");
        printf("\n5. reverse");
        printf("\n6. split");
        printf("\n7. to copy list1");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            list1 = createList(list1);
            break;
        case 2:
            list2 = createList(list2);
            break;
        case 3:
            printf("\nList 1: ");
            display(list1);
            printf("\nList 2: ");
            display(list2);
            break;
        case 4:
            start = concat(list1, list2);
            display(start);
            break;
        case 5:
            list1 = reverse(list1);
            display(list1);
            break;
        case 6:
            printf("\nEnter the position to split: ");
            scanf("%d", &pos);
            split(list1, pos, &first, &second);
            printf("\nFirst: ");
            display(first);
            printf("\nSecond: ");
            display(second);
            break;
        case 7:
            start = copy(list1);
            display(start);
            break;
        default:
            exit(0);
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

void display(struct Node *start)
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
}

struct Node *concat(struct Node *list1, struct Node *list2)
{
    struct Node *ptr;
    ptr = list1;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = list2;

    return list1;
}

struct Node *reverse(struct Node *start)
{
    struct Node *current = start;
    struct Node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void split(struct Node *start, int pos, struct Node **first, struct Node **second)
{
    struct Node *ptr = start;

    if (start == NULL || pos <= 0)
    {
        *first = start;
        *second = NULL;
        return;
    }

    for (int i = 1; ptr->next != NULL && i < pos; i++)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        *first = start;
        *second = NULL;
    }
    else
    {
        *first = start;
        *second = ptr->next;
        ptr->next = NULL;
    }
}

struct Node *copy(struct Node *start)
{
    if (start == NULL)
    {
        return NULL;
    }

    struct Node *head = NULL;
    struct Node *tail = NULL;
    struct Node *temp = start;

    while (temp != NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = temp->data;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        temp = temp->next;
    }

    return head;
}