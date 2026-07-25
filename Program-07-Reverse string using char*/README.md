# Program 7 : Reverse the string using char*
## Write a C program to create a char* and read a string from the keyboard and print the reverse of the string using char*.

## Source code
```c

#include <stdio.h>

#define MAX 100

void push(char stack[], int *top, char ch)
{
    if (*top == MAX)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[*top] = ch;
    (*top)++;
}

char pop(char stack[], int *top)
{
    if (*top == 0)
    {
        return '\0';
    }

    (*top)--;
    return stack[*top];
}

int main()
{
    char str[MAX];
    char stack[MAX];
    char *p;
    int top = 0;
    char ch;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    p = str;

    while (*p != '\0')
    {
        push(stack, &top, *p);
        p++;
    }

    printf("Reversed string: ");

    while (top > 0)
    {
        ch = pop(stack, &top);
        printf("%c", ch);
    }

    printf("\n");

    return 0;
}

```

## Sample Output
```text

Enter a string: Data Structures

Reversed string: serutcurtS ataD
```



