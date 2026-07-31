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
int increaseorder(LINK *l){
    if(l==NULL)
        return 1;
    int a=1;
    LINK *temp=l;
    while(temp->next!=NULL){
        if(temp->data > temp->next->data){
            a=0;
            break;
        }
        temp=temp->next;
    }
    return a;
}
int main()
{
    LINK *l1=makelink(200);
    l1->next=makelink(500);
    l1->next->next=makelink(800);
    l1=inserthead(l1,100);
    l1=inserthead(l1,900);
    printf("\nList 1 : ");
    display(l1);     printf("\n\n");

    int order;
    order=increaseorder(l1);
    if(order)
        printf("Linked list is in the increasing order");
    else
        printf("Linked list is not in the increasing order");

    printf("\n\n");

    return 0;
}

