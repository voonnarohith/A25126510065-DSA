#include <stdio.h>

int main()
{
    int graph[20][20];
    int queue[20];
    int visited[20] = {0};
    int n, start;
    int front = 0, rear = 0;
    int i, current;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        int j;

        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    scanf("%d", &start);

    start--;

    queue[rear++] = start;
    visited[start] = 1;

    printf("Traversal: ");

    while (front < rear)
    {
        current = queue[front++];
        printf("%d ", current + 1);

        for (i = 0; i < n; i++)
        {
            if (graph[current][i] != 0 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");

    return 0;
}