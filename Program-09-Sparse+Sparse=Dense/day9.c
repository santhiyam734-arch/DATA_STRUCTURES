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
