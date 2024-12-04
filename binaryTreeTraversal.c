#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *tree = NULL;

struct Node *insertElement(struct Node *root)
{
    struct Node *ptr, *nodeptr, *parentptr;
    int val;
    printf("\nEnter the data of node: ");
    scanf("%d", &val);
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (root == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;

        while (nodeptr != NULL)
        {
            parentptr = nodeptr;

            if (val < nodeptr->data)
            {
                nodeptr = nodeptr->left;
            }
            else
            {
                nodeptr = nodeptr->right;
            }
        }

        if (val < parentptr->data)
        {
            parentptr->left = ptr;
        }
        else
        {
            parentptr->right = ptr;
        }
    }

    return tree;
}

void preorderTraversal(struct Node *tree)
{
    if (tree != NULL)
    {
        printf("%d\t", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}
void inorderTraversal(struct Node *tree)
{
    if (tree != NULL)
    {
        inorderTraversal(tree->left);
        printf("%d\t", tree->data);
        inorderTraversal(tree->right);
    }
}
void postorderTraversal(struct Node *tree)
{
    if (tree != NULL)
    {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t", tree->data);
    }
}

void main()
{
    int choice;

    while (1)
    {
        printf("\n ******MAIN MENU******* \n");
        printf("\n 1. Insert Element");
        printf("\n 2. Preorder Traversal");
        printf("\n 3. Inorder Traversal");
        printf("\n 4. Postorder Traversal");
        printf("\n 5. Exit");

        printf("\n\n Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            tree = insertElement(tree);
            break;
        case 2:
            printf("\n The elements of the tree are : \n");
            preorderTraversal(tree);
            break;
        case 3:
            printf("\n The elements of the tree are : \n");
            inorderTraversal(tree);
            break;
        case 4:
            printf("\n The elements of the tree are : \n");
            postorderTraversal(tree);
            break;
        case 5:
            exit(0);
            break;
        }
    }
}