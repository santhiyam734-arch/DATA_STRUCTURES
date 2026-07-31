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
LINK *inserttail(LINK *l,int data){
      if(!l)
        return makelink(data);
      LINK *temp=l;
      while(temp->next)
          temp=temp->next;
      temp->next=makelink(data);
      return l;
}
int main()
{
    LINK *l1=makelink(200);
    LINK *l2=makelink(300);
    LINK *l3=NULL;
    l1->next=makelink(500);
    l1->next->next=makelink(800);
    l2=inserthead(l2,100);
    l2=inserttail(l2,900);
    l3=inserthead(l3,700);
    l3=inserttail(l3,400);
    printf("\nList 1 : ");
    display(l1);     printf("\n\n");
    printf("\nList 2 : ");
    display(l2);     printf("\n\n");
    printf("\nList 3 : ");
    display(l3);     printf("\n\n");

    return 0;
}
