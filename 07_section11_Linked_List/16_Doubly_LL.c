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

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    printf("\nLength is %d\n", length(head));
    display(head);
    return 0;
}