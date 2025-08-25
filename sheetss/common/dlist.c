#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

void create(dlist *pl)
{
    pl->head=NULL;
    pl->tail=NULL;
    pl->size=0;
}
void destroy(dlist *pl)
{
    Node *cur=pl->head;
    while(cur)
    {
        cur=cur->next;
        free(pl->head);
        pl->head=cur;
    }
    pl->head=NULL;
    pl->tail=NULL;
    pl->size=0;
}
void insertNode(info e, dlist *list) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) {
        printf("Memory allocation failed\n");
        return;
    }

    n->data = e;
    n->next = NULL;
    n->prev = NULL;

    if (!list->head) {
        list->head = n;
        list->tail = n;
    } else {
        n->prev = list->tail;
        list->tail->next = n;
        list->tail = n;
    }

    list->size++;
}


void deleteNode(info *pe ,dlist *pl)
{
    if (!pl->head) {
        printf("Empty List\n");
        return;
    }

    Node *n = pl->head;
    *pe = n->data;
    pl->head = n->next;

    if (pl->head) {
        pl->head->prev = NULL;
    } else {
        pl->tail = NULL;
    }

    free(n);
    pl->size--;
}

int deleteNodeAtPos(int pos,info *pe,dlist *pl)
{
    if (pos < 0 || pos >= pl->size) {
    printf("Invalid position\n");
    return 0;
    }
    if (!pl->head) {
    printf("Empty List\n");
    return 0;
    }

    Node *tmp=NULL;
    if(pos==0)
    {
        tmp=pl->head;
        *pe=tmp->data;
        pl->head=tmp->next;
        if(pl->head!=NULL)
            pl->head->prev=NULL;
        free(tmp);
        pl->size--;
        return 1;
    }
    Node *curr = pl->head;
    for(int i=0;i<pos-1;i++){
            curr=curr->next;
    }
    tmp = curr->next;
    *pe = tmp->data;

    curr->next = tmp->next;

    if (tmp->next != NULL) {
        tmp->next->prev = curr;
    }

    free(tmp);
    pl->size--;
    return 1;
}
int insertNodeAtPos(int pos,info e,dlist *pl)
{
    if (pos < 0 || pos >pl->size) {
    printf("Invalid position\n");
    return 0;
    }
    Node *n=(Node*)malloc(sizeof(Node));
    if (!n) {
    printf("Memory allocation failure\n");
    return 0;
    }

    n->data=e;
    n->next=NULL;
    n->prev=NULL;

    if(!pl->head)
    {
        pl->head=n;
        pl->tail=n;
    }

    else if(pos==0)
    {
        n->next=pl->head;
        pl->head->prev=n;
        pl->head=n;
    }
    else
    {
        Node *curr = pl->head;
        for(int i=0;i<pos-1;i++){
            curr=curr->next;
            }

        n->next=curr->next;
        n->prev=curr;
        curr->next=n;
        if(n->next!=NULL)
        {
            n->next->prev=n;
        }else{
            pl->tail=n;
        }
    }
    pl->size++;
    return 1;
}
void TraverseAsStack(dlist *pl, void(*pf)(info e)) {
    Node *n = pl->tail;
    while (n) {
        (*pf)(n->data);
        n = n->prev;
    }
}
void TraverseAsQueue(dlist *pl, void(*pf)(info e))
{
    Node *n = pl->head;
    while(n)
    {
        (*pf)(n->data);
        n = n->next;
    }
}
int isEmpty(dlist *pl)
{
    return pl->size==0;
}
int isFull(dlist *pl)
{
    return 0;
}
int listSize(dlist *pl)
{
    return pl->size;
}
