#include <stdio.h>
#include <stdlib.h>
#include "prlist.h"

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
int insertNode(info e, dlist *pl) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) {
        printf("Memory allocation failure\n");
        return 0;
    }

    n->data = e;
    n->next = NULL;
    n->prev = NULL;


    if (!pl->head) {
        pl->head = pl->tail = n;
    }

    else if (e.Pr < pl->head->data.Pr) {
        n->next = pl->head;
        pl->head->prev = n;
        pl->head = n;
    }

    else {
        Node *curr = pl->head;

        while (curr->next && curr->next->data.Pr <= e.Pr) {
            curr = curr->next;
        }

        n->next = curr->next;
        n->prev = curr;
        curr->next = n;

        if (n->next) {
            n->next->prev = n;
        } else {
            pl->tail = n;
        }
    }

    pl->size++;
    return 1;
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

void Traverse(dlist *pl, void(*pf)(info e))
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
