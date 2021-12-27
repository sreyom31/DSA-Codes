#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

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

int count(struct Node *p)
{
    //! Recursive Approach
    if(p==NULL)
        return 0;
    else
        return count(p->next)+1;
}

void Reverse1(struct Node *p) //! Reversal using array method that we should avoid
{
    int *A, i = 0;
    struct Node *q = p;

    A = (int *)malloc(sizeof(int) * count(p));

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void Reverse2(struct Node *p)  //! Reversal using sliding method.
{
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void Reverse3(struct Node *q, struct Node *p) //! Reversal using recursive method.
{
    if (p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
        head = q;
}

int main()
{

    int A[] = {10, 20, 40, 50, 60};
    create(A, 5);

    Reverse1(head);
    Display(head);
    printf("\n");
    return 0;
}