# Program 23 : Sorted linked list (basic functions)
## 	Design a sorted linked list where the values are always retained in increasing or decreasing order. Write functions for inserting 1 value at a time, deleting a value if it exists and print all the values in ascending or descending order.

## Source code
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *makeNode(int data, NODE *next)
{
    NODE *t;

    t = (NODE *)malloc(sizeof(NODE));

    t->data = data;
    t->next = next;

    return t;
}

NODE *inSort(NODE *l, int data)
{
    NODE *t;

    if (l == NULL)
        return makeNode(data, NULL);

    if (l->data >= data)
    {
        t = makeNode(data, l);
        return t;
    }

    l->next = inSort(l->next, data);

    return l;
}

NODE *delSort(NODE *l, int data)
{
    NODE *t;

    if (l == NULL)
        return l;

    if (l->data > data)
        return l;

    if (l->data == data)
    {
        t = l->next;
        free(l);
        return t;
    }

    l->next = delSort(l->next, data);

    return l;
}

void dispAsc(NODE *l)
{
    if (l == NULL)
        return;

    printf("%d ", l->data);

    dispAsc(l->next);
}


void dispDesc(NODE *l)
{
    if (l == NULL)
        return;

    dispDesc(l->next);

    printf("%d ", l->data);
}


int main()
{
    NODE *l = NULL;
    int data;
    int choice;

    while (1)
    {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display Ascending\n");
        printf("4. Display Descending\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter value to insert : ");
                scanf("%d", &data);

                l = inSort(l, data);

                printf("\nValue inserted successfully\n");
                break;


            case 2:
                printf("\nEnter value to delete: ");
                scanf("%d", &data);

                l = delSort(l, data);

                printf("\nAfter deletion: ");
                dispAsc(l);
                printf("\n");
                break;


            case 3:
                printf("\nAscending Order: ");
                dispAsc(l);
                printf("\n");
                break;


            case 4:
                printf("\nDescending Order: ");
                dispDesc(l);
                printf("\n");
                break;

            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}


```

## Sample Output
```text

1. Insert
2. Delete
3. Display Ascending
4. Display Descending

Enter your choice: 1

Enter value to insert : 23

Value inserted successfully

Enter your choice: 1

Enter value to insert : 67

Value inserted successfully

Enter your choice: 1

Enter value to insert : 89

Value inserted successfully

Enter your choice: 1

Enter value to insert : 12

Value inserted successfully

Enter your choice: 2

Enter value to delete: 67

After deletion: 12 23 89

Enter your choice: 3

Ascending Order: 12 23 89

Enter your choice: 4

Descending Order: 89 23 12

```





