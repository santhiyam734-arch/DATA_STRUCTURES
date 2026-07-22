#include <stdio.h>

int magic[30][30];

void oddMagic(int n, int a[30][30])
{
    int i, j, row, col;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            a[i][j] = 0;

    row = 0;
    col = n / 2;

    for (i = 1; i <= n * n; i++)
    {
        a[row][col] = i;

        int newRow = (row - 1 + n) % n;
        int newCol = (col + 1) % n;

        if (a[newRow][newCol] != 0)
            row = (row + 1) % n;
        else
        {
            row = newRow;
            col = newCol;
        }
    }
}

int main()
{
    int n;
    int i, j;

    printf("Enter the order of the magic square: ");
    scanf("%d", &n);

    if (n % 2 != 0)
    {
        printf("This program is only for EVEN magic squares.\n");
        return 0;
    }

    if (n % 4 == 0)
    {
        int num = 1;

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                magic[i][j] = num++;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ((i % 4 == j % 4) || ((i % 4) + (j % 4) == 3))
                    magic[i][j] = n * n + 1 - magic[i][j];
            }
        }
    }

    else
    {
        int m = n / 2;
        int sub[30][30];

        oddMagic(m, sub);

        int add = m * m;

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
            {
                magic[i][j] = sub[i][j];
                magic[i][j + m] = sub[i][j] + 2 * add;
                magic[i + m][j] = sub[i][j] + 3 * add;
                magic[i + m][j + m] = sub[i][j] + add;
            }
        }

        int k = (m - 1) / 2;

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < k; j++)
            {
                int temp = magic[i][j];
                magic[i][j] = magic[i + m][j];
                magic[i + m][j] = temp;
            }
        }

        for (i = 0; i < m; i++)
        {
            for (j = n - k + 1; j < n; j++)
            {
                int temp = magic[i][j];
                magic[i][j] = magic[i + m][j];
                magic[i + m][j] = temp;
            }
        }

        int temp = magic[k][0];
        magic[k][0] = magic[k + m][0];
        magic[k + m][0] = temp;

        temp = magic[k][k];
        magic[k][k] = magic[k + m][k];
        magic[k + m][k] = temp;
    }

    printf("\nMagic Square of order %d:\n\n", n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%4d", magic[i][j]);
        printf("\n");
    }

    return 0;
}
