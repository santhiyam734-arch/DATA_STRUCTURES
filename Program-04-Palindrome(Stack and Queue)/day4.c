#include<stdio.h>
#include<string.h>

#define MAX 50

void pushstack(char stack[],int *top,char c){
    (*top)++;
    stack[*top]=c;
}
void enqueue(char queue[],int *rear,char c){
    (*rear)++;
    queue[*rear]=c;
}
char popstack(char stack[],int *top){
     return stack[(*top)--];
}
char dequeue(char queue[],int *front){
    (*front)++;
     return queue[(*front)];
}

int main()
{
    char stack[MAX];
    char queue[MAX];
    char str[MAX];
    int top=0,front=0,rear=0;
    int i,length,object=1;
    printf("Enter the string : ");
    scanf("%s",str);

    length=strlen(str);

    for(int i=0;i<length;i++){
        pushstack(stack,&top,str[i]);
        enqueue(queue,&rear,str[i]);
    }
    for(int i=0;i<length;i++){
        if(popstack(stack,&top)!=dequeue(queue,&front)){
              object=0;
              break;
        }
    }
    if(object){
        printf("\nThe entered string is a palindrome.\n");
    }else{
        printf("\nThe entered string is not a palindrome.\n");
    }

    return 0;
}
