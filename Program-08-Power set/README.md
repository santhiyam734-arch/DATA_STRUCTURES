# Program 8 : Power set of given set of values 
## Write a C program to generate the power set of given set of values.

## Source code
```c
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

```

## Sample Output
```text

Enter the number of elements: 4
Enter the elements: 7 6 9 3

Power Set:
{ }
{ 7 }
{ 6 }
{ 7 6 }
{ 9 }
{ 7 9 }
{ 6 9 }
{ 7 6 9 }
{ 3 }
{ 7 3 }
{ 6 3 }
{ 7 6 3 }
{ 9 3 }
{ 7 9 3 }
{ 6 9 3 }
{ 7 6 9 3 }

```



