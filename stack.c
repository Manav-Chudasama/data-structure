#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100

void push();
void pop();
void display();

int STACK[MAX], top = -1, size;
void main()
{
    int choice;

    printf("\nEnter the size of stack: ");
    scanf("%d", &size);

    while (1)
    {
        printf("\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("\nInvalid choice.\n");
            break;
        }
    }
}

void push()
{
    int element;
    printf("\nEnter the Element to enter in the stack: ");
    scanf("%d", &element);

    if (top == size - 1)
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        top++;
        STACK[top] = element;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        printf("\nStack Elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", STACK[i]);
        }
    }
}