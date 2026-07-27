# Program 9 : Sparse + Sparse = Dense 
## Write a C program to perform the addition of two sparse matrices to get dense matrices.

## Source code
```c
#include <stdio.h>

int main()
{
    int r, c;
    int n1, n2;
    int i;

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    int dense[r][c];

    for(i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            dense[i][j] = 0;
        }
    }

    printf("Enter number of non-zero elements in first sparse matrix: ");
    scanf("%d", &n1);

    printf("Enter row column value:\n");
    for(i = 0; i < n1; i++)
    {
        int row, col, val;
        scanf("%d%d%d", &row, &col, &val);
        dense[row][col] = val;
    }

    printf("Enter number of non-zero elements in second sparse matrix: ");
    scanf("%d", &n2);

    printf("Enter row column value:\n");
    for(i = 0; i < n2; i++)
    {
        int row, col, val;
        scanf("%d%d%d", &row, &col, &val);
        dense[row][col] += val;
    }

    printf("\nResultant Dense Matrix (Addition of two saparse matrix) :\n");

    for(i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%4d", dense[i][j]);
        }
        printf("\n");
    }

    return 0;
}


```

## Sample Output
```text

Enter rows and columns: 3 3
Enter number of non-zero elements in first sparse matrix: 4
Enter row column value:
0 0 5
1 2 4
2 1 5
0 1 1
Enter number of non-zero elements in second sparse matrix: 4
Enter row column value:
1 0 2
1 2 2
2 1 4
0 1 7

Resultant Dense Matrix (Addition of two saparse matrix) :
   5   8   0
   2   0   6
   0   9   0

```



