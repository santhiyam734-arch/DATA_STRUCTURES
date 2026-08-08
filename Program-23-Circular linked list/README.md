# Program 23 : Circular linked list (basic functions)
## 1.	Design a circular linked list by inserting one value at a time next to the current value. Write functions for searching, printing predecessor and successor node, count of values in linked list and to reverse the linked list.
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
    NODE *t = (NODE *)malloc(sizeof(NODE));
    t->data = data;
    t->next = next;
    return t;
}

NODE *insert(NODE *current, int data)
{
    NODE *t;

    if (current == NULL)
    {
        t = makeNode(data, NULL);
        t->next = t;
        return t;
    }

    t = makeNode(data, current->next);
    current->next = t;

    current = t;

    return current;
}

void display(NODE *current)
{
    NODE *t;

    if (current == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }

    t = current->next; // first node

    printf("\nCircular List : ");

    do
    {
        printf("%d ", t->data);
        t = t->next;
    } while (t != current->next);

    printf("\n");
}

void searchNode(NODE *current, int key)
{
    NODE *prev, *temp;

    if (current == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    prev = current;
    temp = current->next;

    do
    {
        if (temp->data == key)
        {
            printf("\nValue is Found : %d\n", key);
            printf("\nPredecessor : %d\n", prev->data);
            printf("\nSuccessor   : %d\n", temp->next->data);
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != current->next);

    printf("\nValue is Not Found\n");
}

int countNodes(NODE *current)
{
    NODE *t;
    int count = 0;

    if (current == NULL)
        return 0;

    t = current->next;

    do
    {
        count++;
        t = t->next;
    } while (t != current->next);

    return count;
}

NODE *reverseList(NODE *current)
{
    NODE *prev, *curr, *next, *head;

    if (current == NULL || current->next == current)
        return current;

    head = current->next;

    prev = current;
    curr = head;

    do
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    current = head;

    return current;
}

int main()
{
    NODE *current = NULL;
    int choice, value;

    while (1)
    {
        printf("\n");
        printf("1. Insert Next to Current\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Count Nodes\n");
        printf("5. Reverse List\n");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Value : ");
            scanf("%d", &value);
            current = insert(current, value);
            break;

        case 2:
            display(current);
            break;

        case 3:
            printf("\nEnter value to search : ");
            scanf("%d", &value);
            searchNode(current, value);
            break;

        case 4:
            printf("\nNumber of Nodes = %d\n", countNodes(current));
            break;

        case 5:
            current = reverseList(current);
            printf("\nList Reversed Successfully\n");
            break;

        default:
            printf("\nInvalid Choice\n");
        }
    }

    return 0;
}

```

## Sample Output
```text
1. Insert Next to Current
2. Display
3. Search
4. Count Nodes
5. Reverse List

Enter Choice : 1

Enter Value : 67

Enter Choice : 1

Enter Value : 89

Enter Choice : 1

Enter Value : 56

Enter Choice : 2

Circular List : 67 89 56

Enter Choice : 3

Enter value to search : 56

Value is Found : 56

Predecessor : 89

Successor   : 67

Enter Choice : 4

Number of Nodes = 3

Enter Choice : 5

List Reversed Successfully

Enter Choice : 2

Circular List : 56 89 67
```





