//? Insertion Types
//* Insertion at the first ---> here time complexity is 1
//* Insertion after some given position ---> here time complexity ranges from 1 to order of n
//* Insertion after the end ---> here time complexity is always order of n

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int count(struct Node *p)
{
    //! Recursive Approach
    if(p==NULL)
        return 0;
    else
        return count(p->next)+1;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = head;
        head = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
int main()
{

    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    Insert(head, 0, 5);
    Display(head);
    printf("\n");
    return 0;
}