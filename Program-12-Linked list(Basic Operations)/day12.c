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
int countnode(LINK *l){
    int count=0;
    while(l){
        count=count+1;
        l=l->next;
    }
    return count;
}
int countnoderecursive(LINK *l){
    if(!l)
        return 0;
    return 1+countnoderecursive(l->next);
}
int findposition(LINK *l,int data){
     int pos=1;
     while(l){
        if(l->data==data)
            return pos;
        l=l->next;
        pos=pos+1;
     }
     return 0;
}
int findpositionrecursive(LINK *l,int data,int current_pos){
    if(!l)
        return 0;
    if(l->data==data)
        return current_pos;
    return findpositionrecursive(l->next,data,current_pos+1);
}
int findsum(LINK *l){
     if(!l)
        return 0;
     return l->data+findsum(l->next);
}
void printreverse(LINK *l){
     if(l){
         printreverse(l->next);
     printf("%5d",l->data);
     }
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

    int count1,count2;
    count1=countnode(l1);
    printf("\n\nNumber of nodes in the list (iterative) : %d",count1);
    count2=countnoderecursive(l1);
    printf("\n\nNumber of nodes in the list (recursive) : %d",count2);

    int e1,e2,pos1,pos2;
    printf("\n\nEnter the element to search (iterative) :");
    scanf("%d",&e1);
    pos1=findposition(l1,e1);
    printf("\nElement %d is in the position (iterative) : %d",e1,pos1);
    printf("\n\nEnter the element to search (recursive) :");
    scanf("%d",&e2);
    pos2=findpositionrecursive(l1,e2,1);
    printf("\nElement %d is in the position (recursive) : %d",e2,pos2);

    printf("\n\nSum of the datas in the linked list : %d",findsum(l1));
    printf("\n\nReverse of the linked list : ");
    printreverse(l1);
    printf("\n\n\n");
    return 0;
}
