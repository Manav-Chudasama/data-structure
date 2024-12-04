#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

struct Node *poly1 = NULL;
struct Node *poly2 = NULL;
struct Node *result = NULL;

struct Node *createNode(int coeff, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

struct Node *insert(struct Node *poly, int coeff, int exp)
{
    struct Node *newNode;
    newNode = createNode(coeff, exp);

    if (poly == NULL)
    {
        return newNode;
    }
    else
    {
        struct Node *ptr = poly;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }

    return poly;
}

void display(struct Node *poly)
{
    struct Node *ptr = poly;
    while (ptr != NULL)
    {
        printf("%dx%d", ptr->coeff, ptr->exp);
        ptr = ptr->next;
        if (ptr != NULL)
        {
            printf(" + ");
        }
    }
}

struct Node *addPoly(struct Node *poly1, struct Node *poly2, struct Node *result)
{
    struct Node *ptr1 = poly1, *ptr2 = poly2;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exp > ptr2->exp)
        {
            result = insert(result, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
        else if (ptr1->exp < ptr2->exp)
        {
            result = insert(result, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
        else
        {
            result = insert(result, ptr1->coeff + ptr2->coeff, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL)
    {
        result = insert(result, ptr1->coeff, ptr1->exp);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        result = insert(result, ptr2->coeff, ptr2->exp);
        ptr2 = ptr2->next;
    }

    return result;
}
struct Node *subPoly(struct Node *poly1, struct Node *poly2, struct Node *result)
{
    struct Node *ptr1 = poly1, *ptr2 = poly2;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exp > ptr2->exp)
        {
            result = insert(result, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
        else if (ptr1->exp < ptr2->exp)
        {
            result = insert(result, -ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
        else
        {
            result = insert(result, ptr1->coeff - ptr2->coeff, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL)
    {
        result = insert(result, ptr1->coeff, ptr1->exp);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        result = insert(result, -ptr2->coeff, ptr2->exp);
        ptr2 = ptr2->next;
    }

    return result;
}

int main()
{
    // Create first polynomial: 3x^3 + 5x^2 + 6
    poly1 = insert(poly1, 3, 3);
    poly1 = insert(poly1, 5, 2);
    poly1 = insert(poly1, 6, 0);

    // Create second polynomial: 4x^3 + 2x + 1
    poly2 = insert(poly2, 4, 3);
    poly2 = insert(poly2, 2, 1);
    poly2 = insert(poly2, 1, 0);

    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("\nSecond Polynomial: ");
    display(poly2);

    result = NULL;
    // Add polynomials
    result = addPoly(poly1, poly2, result);
    printf("\nSum: ");
    display(result);

    result = NULL;
    // Subtract polynomials
    result = subPoly(poly1, poly2, result);
    printf("\nDifference: ");
    display(result);
}