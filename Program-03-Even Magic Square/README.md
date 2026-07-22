# Program 3 : Even Magic Square
## Write a C program to generate a magic square of even order n using the Siamese method. Accept an even positive integer from the user and display the magic square. A magic square is a square matrix in which the sum of every row, every column, and both main diagonals is the same. If the user enters an odd or non-positive number, display an appropriate error message.

## Source code
```c
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


```
## Sample Output
```text
Enter the order of the magic square: 10

Magic Square of order 10:

  92  99   1   8  15  67  74  51  58  40
  98  80   7  14  16  73  55  57  64  41
   4  81  88  20  22  54  56  63  70  47
  85  87  19  21   3  60  62  69  71  28
  86  93  25   2   9  61  68  75  52  34
  17  24  76  83  90  42  49  26  33  65
  23   5  82  89  91  48  30  32  39  66
  79   6  13  95  97  29  31  38  45  72
  10  12  94  96  78  35  37  44  46  53
  11  18 100  77  84  36  43  50  27  59
```


