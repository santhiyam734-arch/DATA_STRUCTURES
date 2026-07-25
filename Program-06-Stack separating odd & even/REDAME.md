# Program 6 : Stack - Separating odd and even numbers
## Write a C program which generate n number of random numbers: (i)separate all odd numbers into satck1 and even numbers into stack2, (ii)print stack1 and stack2by copying the entire stack.

## Source code
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void push(int stack[], int *top, int value)
{
    if(*top == MAX)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[*top] = value;
    (*top)++;
}

void printStack(int stack[], int top)
{
    while(top > 0)
    {
        top--;
        printf("%d ", stack[top]);
    }
    printf("\n");
}

int main()
{
    int stack1[MAX], stack2[MAX];
    int top1 = 0, top2 = 0;
    int n, i, num;

    printf("Enter the number of random integers: ");
    scanf("%d", &n);

    printf("\nGenerated Numbers:\n");

    for(i = 0; i < n; i++)
    {
        num = rand() % 100 + 1;
        printf("%d ", num);

        if(num % 2 == 0)
            push(stack2, &top2, num);
        else
            push(stack1, &top1, num);
    }

    printf("\n\nStack 1 (Odd Numbers):\n");
    printStack(stack1, top1);

    printf("\nStack 2 (Even Numbers):\n");
    printStack(stack2, top2);

    return 0;
}

```

## Sample Output
```text

Enter the number of random integers: 10

Generated Numbers:
42 68 35 1 70 25 79 59 63 65

Stack 1 (Odd Numbers):
65 63 59 79 25 1 35

Stack 2 (Even Numbers):
70 68 42
```



