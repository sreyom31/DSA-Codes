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

int maxElement(struct Node *p)
{
    int m=-32768;
    //! Normal Approach
    // while(p)
    // {
    //     if(p->data > m)
    //         m=p->data;
    //     p=p->next;
    // }
    // return m;

    //! Recursive Approach
    int x=0;
    if(p==NULL)
        return m;
    x=maxElement(p->next);
    return x>p->data?x:p->data;
    
}

int main()
{
    int A[]={3, 5, 7, 4, 9};
    create(A, 5);
    int max=maxElement(head);
    printf("%d\n", max);
    return 0;
}