# Program 17 : Linked list (Finding the middle node)
## Write a C program to find the value of the middle node in the given linked list.

## Source code
```c

#include<stdio.h>
#include<malloc.h>

typedef struct node{
     int data;
     struct node *next;
}LINK;
void display(LINK *l){
     while(l){
        printf("%5d",l->data);
        l=l->next;
     }
}
LINK *makelink(int data){
     LINK *temp=(LINK *)malloc(sizeof(LINK));
     temp->data=data;
     temp->next=NULL;
     return temp;
}
LINK *inserthead(LINK *l,int data){
     LINK *temp=makelink(data);
     temp->next=l;
     return temp;
}
void middlenode(LINK *l){
     if(l==NULL){
        printf("Linked list is empty.");
        return;
     }
     LINK *aslow=l;
     LINK *bfast=l;
     LINK *prev=NULL;
     while(bfast!=NULL && bfast->next!=NULL){
        prev=aslow;
        aslow = aslow->next;
        bfast = bfast->next->next;
     }
     if (bfast == NULL) {
        printf("First Middle Node  : %d\n", prev->data);
        printf("Second Middle Node : %d\n", aslow->data);
    } else {
        printf("Middle Node : %d\n", aslow->data);
    }
}
int main()
{
    LINK *l1=makelink(200);
    l1->next=makelink(500);
    l1->next->next=makelink(800);
    l1=inserthead(l1,100);
    //l1=inserthead(l1,900);
    printf("\nList 1 : ");
    display(l1);     printf("\n\n");

    middlenode(l1);

    printf("\n\n");

    return 0;
}

```

## Sample Output
```text

// For linked list in odd order

List 1 :   900  100  200  500  800

Middle Node : 200

// For linked list in even order

List 1 :   100  200  500  800

First Middle Node  : 200
Second Middle Node : 500



```





