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

struct Node* searchElement(struct Node *p, int key)
{
    //* Here time and space complexity are both of order n.
    //! Normal Approach (optimised by move to head method)
    struct Node *q=NULL;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=head;
            head=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;

    //! Recursive Approach
    // if(p==NULL)
    //     return NULL;
    // if(key==p->data)
    //     return p;
    // return searchElement(p->next, key);
}

int main()
{
    int A[]={3, 5, 7, 10, 15};
    create(A, 5);
    struct Node *res=searchElement(head, 10);
    if(res)
        printf("Key is found %d\n", res->data);
    else 
        printf("Key not found\n");
    return 0;
}

//? Search optimization

/*
* There are two types of Search optimization. One is transposition and the other is Move to head.
* In Transposition when we found the required element we interchange it with the previous one.
* In move to head we move that specific node to head so that when we try to seach again for that element we will find it in one iteration only.
*/
