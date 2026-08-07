# Program 22 : Evaluating postfix expression
## Consider any postfix expression with binary operators and evaluate the expression.

## Source code
```c


#include <stdio.h>

#define MAX 100

int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return 1;
    else
        return 0;
}

int getValue(char ch)
{
    int value;

    printf("\nEnter the value of %c: ", ch);
    scanf("%d", &value);

    return value;
}

void evaluatePostfix(char exp[])
{
    int stack[MAX];
    int top = 0;
    int i = 0;
    int op1, op2, result;

    while(exp[i] != '\0')
    {
        if(exp[i] >= 'a' && exp[i] <= 'z')
        {
            stack[top] = getValue(exp[i]);
            top++;
        }

        else if(isOperator(exp[i]))
        {
            if(top < 2)
            {
                printf("\nInvalid Expression\n");
                return;
            }

            top--;
            op2 = stack[top];

            top--;
            op1 = stack[top];

            switch(exp[i])
            {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    result = op1 / op2;
                    break;
            }

            stack[top] = result;
            top++;
        }

        i++;
    }

    if(top == 1)
        printf("\nResult = %d", stack[0]);
    else
        printf("\nInvalid Expression\n");
}

int main()
{
    char exp[MAX];

    printf("\nEnter the postfix expression: ");
    scanf("%s", exp);

    evaluatePostfix(exp);

    printf("\n\n");
    return 0;
}

```

## Sample Output
```text

Enter the postfix expression: ab+c-

Enter the value of a: 7

Enter the value of b: 6

Enter the value of c: 5

Result = 8

```





