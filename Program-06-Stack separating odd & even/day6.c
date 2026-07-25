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
