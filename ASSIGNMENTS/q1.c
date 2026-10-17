#include <stdio.h>

int main()
{
    int n, i, key;
    int low, high, mid, found = -1, comparisons = 0;

    scanf("%d", &n);

    int id[n];

    for (i = 0; i < n; i++)
        scanf("%d", &id[i]);

    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        comparisons++;

        if (id[mid] == key)
        {
            found = mid;
            break;
        }

        if (key < id[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (found != -1)
        printf("ID found at position %d\n", found + 1);
    else
        printf("ID not found\n");

    printf("Comparisons: %d\n", comparisons);

    return 0;
}