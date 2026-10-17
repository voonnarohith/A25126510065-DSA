#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert(int value)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
}

void removeItem()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                removeItem();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}