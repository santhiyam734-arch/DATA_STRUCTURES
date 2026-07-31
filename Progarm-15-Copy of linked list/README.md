# Program 15 : Copy of the linked list
## Write a C program to create a copy of the given linked list.

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
LINK *copy(LINK *l){
     if(!l)
        return NULL;
     LINK *temp=makelink(l->data);
     temp->next=copy(l->next);
     return temp;
}
int main()
{
    LINK *l1=makelink(200);
    l1->next=makelink(500);
    l1->next->next=makelink(800);
    l1=inserthead(l1,100);
    l1=inserthead(l1,900);

    LINK *l2=copy(l1);

    printf("\nBefore Modifying : \n ");
    printf("\nList 1 : ");
    display(l1);     printf("\n\n");
    printf("\nList 2 (copied list) : ");
    display(l2);     printf("\n\n");

    l2->next->data=400;

    printf("\nAfter Modifying : \n ");
    printf("\nList 1 : ");
    display(l1);     printf("\n\n");
    printf("\nList 2 (copied list) : ");
    display(l2);     printf("\n\n\n");

    return 0;
}

```

## Sample Output
```text

Before Modifying :

List 1 :   900  100  200  500  800


List 2 (copied list) :   900  100  200  500  800


After Modifying :

List 1 :   900  100  200  500  800


List 2 (copied list) :   900  400  200  500  800


```




