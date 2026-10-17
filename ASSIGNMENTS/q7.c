#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *makeNode(int value)
{
    struct Tree *node =(struct Tree*)malloc(sizeof(struct Tree));

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct Tree *insert(struct Tree *root, int value)
{
    if (root == NULL)
        return makeNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Tree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct Tree *root, int value)
{
    while (root != NULL)
    {
        if (root->data == value)
            return 1;

        if (value < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

int main()
{
    struct Tree *root = NULL;
    int n, i, value;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n");

    scanf("%d", &value);

    if (search(root, value))
        printf("Value exists\n");
    else
        printf("Value does not exist\n");

    return 0;
}