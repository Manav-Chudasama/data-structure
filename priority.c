#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct
{
    int data;
    int priority;
} queue[MAX];

int ptr = -1, size;
int findHighestPriorityIndex()
{

    int index = 0;

    for (int i = 1; i <= ptr; i++)
    {
        if (queue[i].priority > queue[index].priority)
        {
            index = i;
        }
    }

    return index;
}
void insert(int data, int priority)
{
    if (ptr >= size)
    {
        printf("\nQueue is full");
        return;
    }

    ptr++;
    queue[ptr].priority = priority;
    queue[ptr].data = data;
}
void delete()
{
    if (ptr == -1)
    {
        printf("\nUnderflow");
        return;
    }

    int index = findHighestPriorityIndex();

    for (int i = index; i <= ptr - 1; i++)
    {
        queue[i] = queue[i + 1];
    }

    ptr--;
}
void display()
{
    if (ptr == -1)
    {
        printf("\nUnderflow");
        return;
    }
    for (int i = 0; i <= ptr; i++)
    {
        printf("\ndata: %d priority: %d", queue[i].data, queue[i].priority);
    }
}
int main()
{
    int option;
    int val, priority;
    printf("\nEnter the size of the queue: ");
    scanf("%d", &size);
    while (1)
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. DISPLAY");
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter the value and priority to insert: ");
            scanf("%d %d", &val, &priority);
            insert(val, priority);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
            break;
        }
    }
}