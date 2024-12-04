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
    printf("\nEnter the Queue size: ");
    scanf("%d", &size);

    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("\n1. Insert \n2. Delete \n3. Peek \n4. Display \n5. Exit\n");
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
            printf("\nInvalid choice");
            break;
        }
    }
}

void insert()
{
    int element;
    if (rear == size - 1)
    {
        printf("\nQueue is Full");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    printf("\nEnter the element to be inserted: ");
    scanf("%d", &element);

    QUEUE[rear] = element;
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\ndeleting %d", QUEUE[front]);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void peek()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        printf("\nElement is %d", QUEUE[front]);
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nElements in a Queue\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", QUEUE[i]);
        }
    }
}