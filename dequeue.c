#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int queue[MAX], size, left = -1, right = -1;

void insertRight()
{
    int val;
    if (left == 0 && right == size - 1 || left == right + 1)
    {
        printf("\nOverflow");
        return;
    }

    printf("\nEnter the value to insert: ");
    scanf("%d", &val);

    if (right == -1)
    {
        right = left = 0;
    }
    else
    {
        if (right == size - 1)
        {
            right = 0;
        }
        else
        {
            right++;
        }
    }

    queue[right] = val;
}

void insertLeft()
{
    int val;
    if (left == 0 && right == size - 1 || left == right + 1)
    {
        printf("\nOverflow");
        return;
    }

    printf("\nEnter the value to insert: ");
    scanf("%d", &val);

    if (left == -1)
    {
        left = right = 0;
    }
    else
    {
        if (left == 0)
        {
            left = size - 1;
        }
        else
        {
            left--;
        }
    }

    queue[left] = val;
}

void deleteRight()
{
    if (right == -1)
    {
        printf("\nUnderflow");
        return;
    }

    if (left == right)
    {
        left = right = -1;
    }
    else
    {

        if (right == 0)
        {
            right = size - 1;
        }
        else
        {
            right--;
        }
    }
}

void deleteLeft()
{
    if (right == -1)
    {
        printf("\nUnderflow");
        return;
    }

    if (left == right)
    {
        left = right = -1;
    }
    else
    {
        if (left == size - 1)
        {
            left = 0;
        }
        else
        {
            left++;
        }
    }
}

void display()
{
    if (left == -1)
    {
        printf("\nUnderflow");
        return;
    }
    printf("\n");
    if (left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        for (int i = left; i < size; i++)
        {
            printf("%d ", queue[i]);
        }

        for (int i = 0; i <= right; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    int choice;

    printf("\nEnter the size of the queue: ");
    scanf("%d", &size);

    while (1)
    {
        printf("\n INPUT RESTRICTED DEQUE");
        printf("\n 1.Insert at right");
        printf("\n 2.Insert at left");
        printf("\n 3.Delete from right");
        printf("\n 4.Delete from left");
        printf("\n 5.Display");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertRight();
            break;
        case 2:
            insertLeft();
            break;
        case 3:
            deleteRight();
            break;
        case 4:
            deleteLeft();
            break;
        case 5:
            display();
            break;
        }
    }
}