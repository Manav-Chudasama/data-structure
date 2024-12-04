#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack implementation
typedef struct
{
    char items[MAX];
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

void push(Stack *s, char item)
{
    if (!isFull(s))
    {
        s->items[++(s->top)] = item;
    }
}

char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->items[(s->top)--];
    }
    return '\0';
}

char peek(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->items[s->top];
    }
    return '\0';
}

// Helper functions
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Infix to Postfix
void infixToPostfix(char *infix, char *postfix)
{
    Stack s;
    s.top = -1;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];

        if (isalnum(c))
        {
            postfix[j++] = c; // Add operands to postfix
        }
        else if (c == '(')
        {
            push(&s, c); // Push '(' to stack
        }
        else if (c == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[j++] = pop(&s); // Pop until '(' is found
            }
            pop(&s); // Remove '('
        }
        else if (isOperator(c))
        {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }

    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s); // Pop remaining operators
    }
    postfix[j] = '\0'; // Null-terminate the string
}

// Infix to Prefix
void infixToPrefix(char *infix, char *prefix)
{
    char reversed[MAX];
    strcpy(reversed, infix);
    strrev(reversed);

    for (int i = 0; reversed[i] != '\0'; i++)
    {
        if (reversed[i] == '(')
            reversed[i] = ')'; // Swap '(' with ')'
        else if (reversed[i] == ')')
            reversed[i] = '(';
    }

    char postfix[MAX];
    infixToPostfix(reversed, postfix); // Get postfix of reversed expression
    strcpy(prefix, postfix);
    strrev(prefix); // Reverse the postfix to get prefix
}

// Main function
int main()
{
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    printf("Postfix: %s\n", postfix);
    printf("Prefix: %s\n", prefix);

    return 0;
}
