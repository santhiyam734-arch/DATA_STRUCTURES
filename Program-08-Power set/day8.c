#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int set[n];

    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }

    int total = 1;

    for(i = 0; i < n; i++)
    {
        total = total * 2;
    }

    printf("\nPower Set:\n");

    for(i = 0; i < total; i++)
    {
        printf("{ ");

        for(j = 0; j < n; j++)
        {
            if(i & (1 << j))
            {
                printf("%d ", set[j]);
            }
        }

        printf("}\n");
    }

    return 0;
}
