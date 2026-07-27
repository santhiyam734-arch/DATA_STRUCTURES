#include <stdio.h>

#define MAX 100

int main()
{
    char stack[MAX], exp[MAX];
    int top = 0;
    int i;
    char ch;

    printf("Enter the expression: ");
    scanf("%s", exp);

    for(i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            stack[top] = exp[i];
            top++;
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(top == 0)
            {
                printf("Brackets are not Balanced");
                return 0;
            }

            top--;
            ch = stack[top];

            if((exp[i] == ')' && ch != '(') ||
               (exp[i] == '}' && ch != '{') ||
               (exp[i] == ']' && ch != '['))
            {
                printf("Brackeets are not Balanced");
                return 0;
            }
        }
    }

    if(top == 0)
        printf("Brackets are Balanced");
    else
        printf("Brackets are not Balanced");

    return 0;
}
