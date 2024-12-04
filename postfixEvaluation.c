#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
    int data[MAX];
    int top;
} Stack;

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

int evaluatePostfix(const char *expression)
{
    Stack stack = {.top = -1}; // Initialize stack directly

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isdigit(expression[i]))
        {
            push(&stack, expression[i] - '0');
        }
        else
        {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            switch (expression[i])
            {
            case '+':
                push(&stack, val2 + val1);
                break;
            case '-':
                push(&stack, val2 - val1);
                break;
            case '*':
                push(&stack, val2 * val1);
                break;
            case '/':
                push(&stack, val2 / val1);
                break;
            default:
                printf("Invalid operator\n");
                exit(1);
            }
        }
    }
    return pop(&stack);
}

int main()
{
    char expression[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("The result of the postfix evaluation is: %d\n", result);

    return 0;
}

// Output:
// Enter a postfix expression: 23*54*+
// The result of the postfix evaluation is: 26
