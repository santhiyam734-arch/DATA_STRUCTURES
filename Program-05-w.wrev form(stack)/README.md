# Program 5 : Checking w.wrev form (stack)
## Write a C program to check whether the string entered is in the form w.wrev or not by using stack.

## Source code
```c
#include<stdio.h>
#include<string.h>

#define MAX 50

void push(char stack[],int *top,char c){
     stack[*top]=c;
     (*top)++;
}

char pop(char stack[],int *top){
    (*top)--;
    return stack[*top];
}

int main()
{
    char str[MAX];
    char stack[MAX];
    int top=0;
    int dot=0,found=0,obj=1;

    printf("Enter the string to check :");
    scanf("%s",str);

    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='.'){
            dot=i;
            found=1;
            break;
        }
    }

    if(found==0){
        printf("Invalid string format");
        return 0;
    }

    for(int i=0;i<dot;i++){
        push(stack,&top,str[i]);
    }

    for(int i=dot+1;str[i]!='\0';i++){
        if(top==0){
            obj=0;
            break;
        }
        if(pop(stack,&top)!=str[i]){
            obj=0;
            break;
        }
    }

    if(top!=0){
        obj=0;
    }
    if(obj==1){
        printf("\nThe string is in w.wrev form.\n");
    }else{
        printf("\nThe string is not in w.wrev form.\n");
    }

    return 0;
}

```

## Sample Output
```text

Enter the string to check :form.mrof

The string is in w.wrev form.

```



