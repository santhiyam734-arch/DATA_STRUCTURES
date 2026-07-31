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
LINK *concatenate(LINK *l1,LINK *l2){
     if(l1==NULL && l2==NULL)
        return NULL;
     if(l1==NULL)
        return copy(l2);
     LINK *l3=copy(l1);
     LINK *temp=l3;
     while(temp->next != NULL){
        temp=temp->next;
     }
     temp->next=copy(l2);
     return l3;
}
int main()
{
    LINK *l1=makelink(200);
    l1->next=makelink(500);
    l1->next->next=makelink(800);
    l1=inserthead(l1,100);
    l1=inserthead(l1,900);

    LINK *l2=makelink(700);
    l2=inserthead(l2,300);
    l2=inserthead(l2,400);
    l2=inserthead(l2,600);

    LINK *l3=concatenate(l1,l2);

    printf("\nList 1 : ");
    display(l1);     printf("\n\n");
    printf("\nList 2 : ");
    display(l2);     printf("\n\n");

    printf("\nConctaenated Linked list : \n ");
    printf("\nList 3 : ");
    display(l3);     printf("\n\n\n");

    return 0;
}

