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
int sameornot(LINK *l1,LINK *l2){
     while(l1!=NULL && l2!=NULL){
        if(l1->data != l2->data){
            return 0;
        }
        l1=l1->next;
        l2=l2->next;
     }
     return  (l1==NULL && l2==NULL);
}
int main()
{
    LINK *l1=makelink(200);
    l1->next=makelink(500);
    l1->next->next=makelink(800);
    l1=inserthead(l1,100);
    l1=inserthead(l1,900);

    LINK *l2=makelink(800);
    l2=inserthead(l2,500);
    l2=inserthead(l2,200);
    l2=inserthead(l2,100);
    l2=inserthead(l2,900);

    printf("\nList 1 : ");
    display(l1);     printf("\n\n");
    printf("\nList 2 : ");
    display(l2);     printf("\n\n");

    int same;
    same=sameornot(l1,l2);
    if(same)
        printf("The two Linked lists are same");
    else
        printf("The two Linked list are not same");

    printf("\n\n");

    return 0;
}


