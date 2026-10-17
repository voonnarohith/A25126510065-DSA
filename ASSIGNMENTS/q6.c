#include <stdio.h>
#include <stdlib.h>

struct Page
{
    int page;
    struct Page *prev;
    struct Page *next;
};

struct Page *first = NULL;

void addPage(int value)
{
    struct Page *node = (struct Page*)malloc(sizeof(struct Page));
    struct Page *temp;

    node->page = value;
    node->next = NULL;
    node->prev = NULL;

    if (first == NULL)
    {
        first = node;
        return;
    }

    temp = first;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
    node->prev = temp;
}

void forward()
{
    struct Page *temp = first;

    if (temp == NULL)
    {
        printf("No pages\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->page);
        temp = temp->next;
    }

    printf("\n");
}

void backward()
{
    struct Page *temp = first;

    if (temp == NULL)
        return;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL)
    {
        printf("%d ", temp->page);
        temp = temp->prev;
    }

    printf("\n");
}

void deletePage(int value)
{
    struct Page *temp = first;

    while (temp != NULL && temp->page != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Page not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        first = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

int main()
{
    int n, i, value;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        addPage(value);
    }

    forward();
    backward();

    scanf("%d", &value);
    deletePage(value);

    forward();
    backward();

    return 0;
}