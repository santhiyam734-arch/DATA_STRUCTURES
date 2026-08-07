# Program 20 : Parenthesized expression into postfix expression
## Given a fully parenthesized expression with binary and unary operators. Find the equivalent Postfix Expression.

## Source code
```c

#include <stdio.h>

#define MAX 100

int isOperand(char ch)
{
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        return 1;
    else
        return 0;
}

int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
        return 1;
    else
        return 0;
}

void infixToPostfix(char exp[])
{
    char stack[MAX];
    int top = 0;
    int i = 0;

    printf("\nPostfix Expression : ");

    while(exp[i] != '\0')
    {
        if(isOperand(exp[i]))
        {
            printf("%c", exp[i]);
        }

        else if(exp[i] == '(')
        {
            stack[top] = exp[i];
            top++;
        }

        else if(isOperator(exp[i]))
        {
            stack[top] = exp[i];
            top++;
        }

        else if(exp[i] == ')')
        {
            while(top > 0 && stack[top-1] != '(')
            {
                top--;
                printf("%c", stack[top]);
            }

            if(top > 0)
                top--;
        }

        i++;
    }

    while(top > 0)
    {
        top--;

        if(stack[top] != '(')
            printf("%c", stack[top]);
    }

    printf("\n");
}

int main()
{
    char exp[MAX];

    printf("\nEnter Fully Parenthesized Expression: ");
    scanf("%s", exp);

    infixToPostfix(exp);

    return 0;
}

```

## Sample Output
```text

Enter Fully Parenthesized Expression: ((a+b)*c)

Postfix Expression : ab+c*

```





