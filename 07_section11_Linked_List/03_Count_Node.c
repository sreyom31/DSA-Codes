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

int countNodes(struct Node *p)
{
    //* Here time and space complexity are both of order n and total instances are n+1. +1 for null instance
    //! Normal Approach
    // int count=0;
    // while(p!=NULL)
    // {
    //     count++;
    //     p=p->next;
    // }
    // return count;

    //! Recursive Approach
    if(p==NULL)
        return 0;
    else
        return countNodes(p->next)+1;
}

int main()
{
    int A[]={3, 5, 7, 10, 15};
    create(A, 5);
    int count=countNodes(head);
    printf("%d\n", count);
    return 0;
}