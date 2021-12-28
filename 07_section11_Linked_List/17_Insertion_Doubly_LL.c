#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*head=NULL;

typedef struct Node node;

void create(int A[], int n)
{
    node *t, *last;
    head=(node *)malloc(sizeof(node));
    head->data=A[0];
    head->prev=head->next=NULL;
    last=head;

    for (int i = 1; i < n; i++)
    {
        t=(node *)malloc(sizeof(node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
    
}

void display(node *p)
{
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int length(node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p=p->next;
    }
    return len;
}

void Insert(node *p, int index, int x)
{
    node *t;
    if(index < 0 || index > length(p))
        return;
    if(index==0)
    {
        t=(node *)malloc(sizeof(node));
        t->data=x;
        t->prev=NULL;
        t->next=head;
        head->prev=t;
        head=t;
    }
    else
    {
        for (int i = 0; i < index-1; i++)
        {
            p=p->next;
        }
        t=(node *)malloc(sizeof(node));
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next) p->next->prev=t;
        p->next=t;
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    printf("\nLength is %d\n", length(head));
    Insert(head, 2, 25);
    display(head);
    return 0;
}