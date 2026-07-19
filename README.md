# Data Structures in C
# Program 1 : Generate all possible permutations of given list of symbols as values.
## Source code
```c
#include<stdio.h>
#include<string.h>

void swap(char *a,char *b){
      char temp;
      temp=*a;
      *a=*b;
      *b=temp;
}
void permutation(char str[],int start,int end){
      if(start==end){
        printf("%s\n",str);
      }
      else{
        for(int i=start;i<=end;i++){
            swap(&str[start],&str[i]);
            permutation(str,start+1,end);
            swap(&str[start],&str[i]);
        }
      }
}
int main()
{
     char str[30];
     printf("Enter the list of symbols :");
     scanf("%s",&str);
     permutation(str,0,strlen(str)-1);
     
     return 0;
}
```
## Sample Output
```text
Enter the list of symbols :ABC
ABC
ACB
BAC
BCA
CBA
CAB
```
