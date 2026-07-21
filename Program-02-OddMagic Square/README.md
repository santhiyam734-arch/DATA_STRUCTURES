# Program 2 : Odd Magic Square
## Write a C program to generate a magic square of odd order n using the Siamese method. Accept an odd positive integer from the user and display the magic square. A magic square is a square matrix in which the sum of every row, every column, and both main diagonals is the same. If the user enters an even or non-positive number, display an appropriate error message.

## Source code
```c
#include <stdio.h>

int main() {
    int n;

    printf("Enter a positive odd number: ");
    scanf("%d", &n);

    if (n <= 0 || n % 2 == 0) {
        printf("Error: Please enter a positive odd number.\n");
        return 1;
    }

    int magic[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magic[i][j] = 0;
        }
    }

    int i = 0;
    int j = n / 2;

    for (int num = 1; num <= n * n; num++) {
        magic[i][j] = num;

        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;

        if (magic[newi][newj] != 0) {
            i = (i + 1) % n;
        } else {
            i = newi;
            j = newj;
        }
    }

    printf("\nMagic Square of order %d:\n\n", n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", magic[i][j]);
        }
        printf("\n");
    }

    return 0;
}

```
## Sample Output
```text
Enter a positive odd number: 5

Magic Square of order 5:

  17  24   1   8  15
  23   5   7  14  16
   4   6  13  20  22
  10  12  19  21   3
  11  18  25   2   9
```

