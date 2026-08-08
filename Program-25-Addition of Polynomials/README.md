# Program 25 : Addition of Polynomials
## Program to add two polynomials represented by arrays.

## Source code
```c
#include <stdio.h>

#define MAX 100

typedef struct
{
    int coeff;
    int exp;
} POLY;

int getPoly(POLY p[])
{
    int n, i;

    printf("\nEnter number of terms: ");
    scanf("%d", &n);

    printf("\nEnter coefficient and exponent:\n");

    for (i = 0; i < n; i++)
    {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &p[i].coeff, &p[i].exp);
    }

    return n;
}

void sortPoly(POLY p[], int n)
{
    int i, j;
    POLY temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].exp < p[j].exp)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int addPoly(POLY p1[], int n1, POLY p2[], int n2, POLY result[])
{
    int i, j, k = 0;
    int found;

    for (i = 0; i < n1; i++)
    {
        result[k] = p1[i];
        k++;
    }

    for (i = 0; i < n2; i++)
    {
        found = 0;

        for (j = 0; j < k; j++)
        {
            if (result[j].exp == p2[i].exp)
            {
                result[j].coeff =
                    result[j].coeff + p2[i].coeff;

                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            result[k] = p2[i];
            k++;
        }
    }

    return k;
}

void display(POLY p[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (i > 0 && p[i].coeff >= 0)
            printf(" + ");

        if (p[i].coeff < 0)
            printf(" - ");

        if (p[i].coeff < 0)
            printf("%d", -p[i].coeff);
        else
            printf("%d", p[i].coeff);

        if (p[i].exp > 1)
            printf("x^%d", p[i].exp);
        else if (p[i].exp == 1)
            printf("x");
    }

    printf("\n");
}


int main()
{
    POLY p1[MAX], p2[MAX], result[MAX];

    int n1, n2, n3;

    printf("\nEnter Polynomial 1\n");
    n1 = getPoly(p1);

    printf("\nEnter Polynomial 2\n");
    n2 = getPoly(p2);

    n3 = addPoly(p1, n1, p2, n2, result);

    sortPoly(result, n3);

    printf("\nPolynomial 1: ");
    display(p1, n1);

    printf("\nPolynomial 2: ");
    display(p2, n2);

    printf("\nSum: ");
    display(result, n3);

    return 0;
}

```

## Sample Output
```text
Enter Polynomial 1

Enter number of terms: 3

Enter coefficient and exponent:
Term 1: 3 3
Term 2: 6 2
Term 3: 1 0

Enter Polynomial 2

Enter number of terms: 4

Enter coefficient and exponent:
Term 1: 6 3
Term 2: 1 2
Term 3: 9 1
Term 4: 5 0

Polynomial 1: 3x^3 + 6x^2 + 1

Polynomial 2: 6x^3 + 1x^2 + 9x + 5

Sum: 9x^3 + 7x^2 + 9x + 6

```





