#ifndef PRLIST_H_INCLUDED
#define PRLIST_H_INCLUDED


typedef struct data{
    char id[10];
    int Pr;
}info;

typedef struct node{
    struct node *prev;
    struct node *next;
    info data;
}Node;

typedef struct list{
    Node *head;
    Node *tail;
    int size;
}dlist;

void create(dlist *pl);
void destroy(dlist *pl);
int insertNode(info e,dlist *pl);
void deleteNode(info *pe ,dlist *pl);
void Traverse(dlist *pl,void(*pf)(info e));
int isEmpty(dlist *pl);
int isFull(dlist *pl);
int listSize(dlist *pl);
#endif // PRLIST_H_INCLUDED
