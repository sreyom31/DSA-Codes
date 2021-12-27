//? Insertion Types
//* Insertion at the first ---> here time complexity is 1
//* Insertion after some given position ---> here time complexity ranges from 1 to order of n
//* Insertion after the end ---> here time complexity is always order of n

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} list;

void linkedListTraversal(list *head)
{
    list *ptr = head;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

list *insertAtFirst(list *head, int data)
{
    list *ptr = (list*)malloc(sizeof(list));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

list *insertAtEnd(list *head, int data)
{
    list *ptr = (list*)malloc(sizeof(list));
    ptr->data = data;
    list *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

list * insertAtIndex (list *head, int data, int index){
    list *ptr = (list*)malloc(sizeof(list));
    list *p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

list * insertAfterNode (list *head, int data, list *prevNode) {
    list *ptr = (list*)malloc(sizeof(list));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main()
{
    list *head, *second, *third, *fourth;
    head = (list*)malloc(sizeof(list));
    second = (list*)malloc(sizeof(list));
    third = (list*)malloc(sizeof(list));
    fourth = (list*)malloc(sizeof(list));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 41;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = NULL;

    printf("Linked list before Insertion\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 8);
    // head = insertAtEnd(head, 8);
    // head = insertAtIndex(head, 8, 2);
    // head = insertAfterNode(head, 8, second);
    printf("Linked list after Insertion\n");
    linkedListTraversal(head);

    return 0;
}