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

int delete(node *p, int index)
{
    node *q; int x = -1;
    if(index < 1 || index > length(p))
        return -1;
    if(index==1)
    {
        head=head->next;
        if(head)
            head->prev=NULL;
        x=p->data;
        free(p);
    } 
    else 
    {
        for (int i = 0; i < index - 1; i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next) p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
    return x;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    printf("\nLength is %d\n", length(head));
    int x = delete(head, 1);
    printf("%d valued node is deleted\n", x);
    display(head);
    return 0;
}