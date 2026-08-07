#include <stdio.h>

#define MAX 100

void validate(char exp[])
{
    char queue[MAX];
    int front = 0, rear = 0;
    int i = 0;
    char ch;

    while(exp[i] != '\0')
    {
        if(exp[i] >= 'A' && exp[i] <= 'Z')
        {
            queue[rear] = exp[i];
            rear++;
        }

        else if(exp[i] >= 'a' && exp[i] <= 'z')
        {
            if(front == rear)
            {
                printf("\nInvalid Expression\n");
                return;
            }

            ch = queue[front];
            front++;

            if(ch + 32 != exp[i])
            {
                printf("\nInvalid Expression\n");
                return;
            }
        }

        else
        {
            printf("\nInvalid Expression\n");
            return;
        }

        i++;
    }

    if(front == rear)
        printf("\nValid Expression\n");
    else
        printf("\nInvalid Expression\n");
}

int main()
{
    char exp[MAX];

    printf("\nEnter the function call and return expression: ");
    scanf("%s", exp);

    validate(exp);

    return 0;
}
