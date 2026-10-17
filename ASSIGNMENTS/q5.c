#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int roll;
    struct Node *next;
};

struct Node *head = NULL;

void display()
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->roll);
        temp = temp->next;
    }

    printf("\n");
}

void insertBeginning(int value)
{
    struct Node *newNode =(struct Node*) malloc(sizeof(struct Node));

    newNode->roll = value;
    newNode->next = head;
    head = newNode;

    display();
}

void insertEnd(int value)
{
    struct Node *newNode =(struct Node*) malloc(sizeof(struct Node));
    struct Node *temp;

    newNode->roll = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    display();
}

void search(int value)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->roll == value)
        {
            printf("Roll number found\n");
            return;
        }

        temp = temp->next;
    }

    printf("Roll number not found\n");
}

void deleteNode(int value)
{
    struct Node *temp = head;
    struct Node *previous = NULL;

    while (temp != NULL && temp->roll != value)
    {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Roll number not found\n");
        return;
    }

    if (previous == NULL)
        head = temp->next;
    else
        previous->next = temp->next;

    free(temp);
    display();
}

int main()
{
    int n, i, value;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertEnd(value);
    }

    scanf("%d", &value);
    insertBeginning(value);

    scanf("%d", &value);
    insertEnd(value);

    scanf("%d", &value);
    search(value);

    scanf("%d", &value);
    deleteNode(value);

    return 0;
}