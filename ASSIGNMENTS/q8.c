#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int value)
{
    struct Node *node =(struct Node*) malloc(sizeof(struct Node));

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct Node *add(struct Node *root, int value)
{
    if (root == NULL)
        return newNode(value);

    if (value < root->value)
        root->left = add(root->left, value);
    else if (value > root->value)
        root->right = add(root->right, value);

    return root;
}

void show(struct Node *root)
{
    if (root != NULL)
    {
        show(root->left);
        printf("%d ", root->value);
        show(root->right);
    }
}

struct Node *smallest(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

struct Node *removeNode(struct Node *root, int value)
{
    struct Node *temp;

    if (root == NULL)
        return NULL;

    if (value < root->value)
    {
        root->left = removeNode(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = removeNode(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = smallest(root->right);
        root->value = temp->value;
        root->right = removeNode(root->right, temp->value);
    }

    return root;
}

int main()
{
    struct Node *root = NULL;
    int n, i, value, target;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = add(root, value);
    }

    printf("Before deletion: ");
    show(root);

    printf("\n");

    scanf("%d", &target);

    root = removeNode(root, target);

    printf("After deletion: ");
    show(root);

    printf("\n");

    return 0;
}