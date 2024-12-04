#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int QUEUE[MAX], size, front = -1, rear = -1;

void insert();
void delete();
void peek();
void display();

void main()
{
    int choice;

    printf("\nEnter the size of he queue: ");
    scanf("%d", &size);

    while (1)
    {
        printf("\n1. Insert \n2. Delete \n3. Peek \n4. Display \n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nSelect a valid option!");
            break;
        }
    }
}

void insert()
{
    int element;

    if (rear == size - 1 && front == 0)
    {
        printf("\nOverflow");
        return;
    }

    printf("\nEnter the element to be inserted: ");
    scanf("%d", &element);

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        QUEUE[rear] = element;
    }
    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        QUEUE[rear] = element;
    }
    else
    {
        rear++;
        QUEUE[rear] = element;
    }
}

void delete()
{
    if (front == -1)
    {
        printf("\nUnderflow");
        return;
    }   
    printf("\nElememt deleted: %d", QUEUE[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        if (front == size - 1)  
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

void peek()
{
    if (front == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\n front element: %d", QUEUE[front]);
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nElements: ");
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d ", QUEUE[i]);
            }
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                printf("%d ", QUEUE[i]);
            }

            for (int i = 0; i <= rear; i++)
            {
                printf("%d ", QUEUE[i]);
            }
        }
    }
}