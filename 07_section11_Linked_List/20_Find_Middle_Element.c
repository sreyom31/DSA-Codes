#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

typedef struct Node node;

void create(int A[], int n)
{
    node *last, *p;
    head=(node*)malloc(sizeof(node));
    head->data=A[0];
    head->next=NULL;
    last=head;

    for (int i = 1; i < n; i++)
    {
        p=(node*)malloc(sizeof(node));
        p->data=A[i];
        last->next=p;
        p->next=NULL;
        last=p;
    }
    
}

void display(node *p)
{
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

node* findMiddle(node *h)
{
    node *p, *q;
    p=q=h;
    while(q)
    {
        q=q->next;
        if(q) q=q->next;
        if(q) p=p->next;
    }
    return p;
}

int main()
{
    int A[]={10, 20, 30, 40, 50};
    create(A, 5);
    display(head);
    printf("\n");
    node *res=findMiddle(head);
    printf("The middle node's data is %d\n", res->data);
    return 0;
}