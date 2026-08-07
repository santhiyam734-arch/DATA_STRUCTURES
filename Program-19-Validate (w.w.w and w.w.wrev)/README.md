# Program 19 : Validate the patterns w.w.w and w.w.wrev
## Write a C program to validate the following patterns using suitable data structures 1)w.w.w 2)w.w.wrev

## Source code
```c

#include <stdio.h>

#define MAX 100

void validateWWW(char input[])
{
    char queue[MAX];
    int front = 0, rear = 0;
    int i = 0;

    while(input[i] != '.')
    {
        queue[rear] = input[i];
        rear++;
        i++;
    }

    i++;
    front = 0;

    while(input[i] != '.')
    {
        if(front == rear || queue[front] != input[i])
        {
            printf("\nInvalid Pattern\n");
            return;
        }

        front++;
        i++;
    }

    if(front != rear)
    {
        printf("\nInvalid Pattern\n");
        return;
    }

    i++;
    front = 0;

    while(input[i] != '\0')
    {
        if(front == rear || queue[front] != input[i])
        {
            printf("\nInvalid Pattern\n");
            return;
        }

        front++;
        i++;
    }

    if(front == rear)
        printf("\nValid Pattern\n");
    else
        printf("\nInvalid Pattern\n");
}

void validateWWWRev(char input[])
{
    char queue[MAX], stack[MAX];
    int front = 0, rear = 0;
    int top = 0;
    int i = 0;

    while(input[i] != '.')
    {
        queue[rear] = input[i];
        rear++;

        stack[top] = input[i];
        top++;

        i++;
    }

    i++;
    front = 0;

    while(input[i] != '.')
    {
        if(front == rear || queue[front] != input[i])
        {
            printf("\nInvalid Pattern\n");
            return;
        }

        front++;
        i++;
    }

    if(front != rear)
    {
        printf("\nInvalid Pattern\n");
        return;
    }

    i++;

    while(input[i] != '\0')
    {
        if(top == 0)
        {
            printf("\nInvalid Pattern\n");
            return;
        }

        top--;

        if(stack[top] != input[i])
        {
            printf("\nInvalid Pattern\n");
            return;
        }

        i++;
    }

    if(top == 0)
        printf("\nValid Pattern\n");
    else
        printf("\nInvalid Pattern\n");
}

int main()
{
    int choice;
    char input[MAX];


    printf("PATTERN VALIDATION : \n");
    printf("1. Validate w.w.w\n");
    printf("2. Validate w.w.wrev\n");

    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter the input string: ");
            scanf("%s",input);
            validateWWW(input);
            break;

        case 2:
            printf("\nEnter the input string: ");
            scanf("%s",input);
            validateWWWRev(input);
            break;

        default:
            printf("\nInvalid Choice\n");
    }

    return 0;
}

```

## Sample Output
```text

PATTERN VALIDATION :
1. Validate w.w.w
2. Validate w.w.wrev

Enter your choice: 1

Enter the input string: sfg.sfg.sfg

Valid Pattern

Enter your choice: 2

Enter the input string: sdg.sdg.sdg

Invalid Pattern


```





