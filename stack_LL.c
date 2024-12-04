#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;
struct Node *push(struct Node *);
struct Node *pop(struct Node *);
void peek(struct Node *);
void display(struct Node *);

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. push \n2. pop \n3. peek \n4. display");
        printf("\nEnter Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            {
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                display(top);
                break;
            default:
                exit(0);
                break;
            }
        }
    }
}

struct Node *push(struct Node *top)
{
    struct Node *newNode;
    int val;

    printf("\nEnter the value you want to push: ");
    scanf("%d", &val);
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    if (top == NULL)
    {
        newNode->next = NULL;
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }

    return top;
}

struct Node *pop(struct Node *top)
{
    struct Node *ptr;
    if (top == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        ptr = top;
        top = top->next;

        free(ptr);
    }

    return top;
}

void peek(struct Node *top)
{
    if (top == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\ntop element: %d", top->data);
    }
}

void display(struct Node *top)
{
    struct Node *ptr;
    if (top == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\n");
        ptr = top;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}