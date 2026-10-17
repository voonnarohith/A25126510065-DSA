#include <stdio.h>

int main()
{
    int n, i, j, current, shifts = 0;

    scanf("%d", &n);

    int marks[n];

    for (i = 0; i < n; i++)
        scanf("%d", &marks[i]);

    for (i = 1; i < n; i++)
    {
        current = marks[i];
        j = i - 1;

        while (j >= 0 && marks[j] > current)
        {
            marks[j + 1] = marks[j];
            j--;
            shifts++;
        }

        marks[j + 1] = current;

        for (j = 0; j < n; j++)
            printf("%d ", marks[j]);

        printf("\n");
    }

    printf("Sorted list: ");

    for (i = 0; i < n; i++)
        printf("%d ", marks[i]);

    printf("\nTotal shifts: %d\n", shifts);

    return 0;
}