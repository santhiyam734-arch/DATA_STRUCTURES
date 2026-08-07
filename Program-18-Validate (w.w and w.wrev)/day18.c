#include <stdio.h>

#define MAX 100

void validateWW(char input[])
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

    while(input[i] != '\0')
    {
        if(front == rear)
        {
            printf("\nInvalid Pattern\n");
            return;
        }

        if(queue[front] != input[i])
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

void validateWRev(char input[])
{
    char stack[MAX];
    int top = 0;
    int i = 0;

    while(input[i] != '=')
    {
        stack[top] = input[i];
        top++;
        i++;
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

    printf("PATTERN VALIDATION :\n");
    printf("1. Validate w.w\n");
    printf("2. Validate w=wrev\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter the input string: ");
            scanf("%s", input);
            validateWW(input);
            break;
        case 2:
            printf("\nEnter the input string: ");
            scanf("%s", input);
            validateWRev(input);
            break;
        default:
            printf("\nInvalid Choice\n");
     }

    return 0;
}
