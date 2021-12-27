#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void create(int A[], int n) {
    struct Node *t, *last;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=NULL;
    last=head;

    for (int i = 1; i < n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}

void display(struct Node *p) //* Here time and space complexity are both of order n and total instances are n+1. +1 for null instance
{
    //! This will print the list in the original order
    // if(p!=NULL)
    // {
    //     printf("%d ", p->data);
    //     display(p->next);
    // }

    //! This will print the list in the reversal order
        if(p!=NULL)
    {
        display(p->next);
        printf("%d ", p->data);
    }
}

int main()
{
    int A[]={3, 5, 7, 10, 15};
    create(A, 5);
    display(head);
    printf("\n");
    return 0;
}