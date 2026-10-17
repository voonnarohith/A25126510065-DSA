#include <stdio.h>

#define INF 99999

int main()
{
    int cost[20][20];
    int distance[20], used[20] = {0};
    int n, source;
    int i, j, next, smallest;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    scanf("%d", &source);
    source--;

    for (i = 0; i < n; i++)
        distance[i] = cost[source][i];

    distance[source] = 0;
    used[source] = 1;

    for (i = 1; i < n; i++)
    {
        smallest = INF;
        next = -1;

        for (j = 0; j < n; j++)
        {
            if (!used[j] && distance[j] < smallest)
            {
                smallest = distance[j];
                next = j;
            }
        }

        if (next == -1)
            break;

        used[next] = 1;

        for (j = 0; j < n; j++)
        {
            if (!used[j] && cost[next][j] != INF &&
                distance[next] + cost[next][j] < distance[j])
            {
                distance[j] = distance[next] + cost[next][j];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (distance[i] == INF)
            printf("%d -> No path\n", i + 1);
        else
            printf("%d -> %d\n", i + 1, distance[i]);
    }

    return 0;
}