#ifndef DLIST_H_INCLUDED
#define DLIST_H_INCLUDED


typedef struct data{
    int key;
    int val;
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
void insertNode(info e,dlist *list);
void deleteNode(info *pe ,dlist *pl);
int deleteNodeAtPos(int pos,info *pe,dlist *pl);
int insertNodeAtPos(int pos,info e,dlist *pl);
void TraverseAsStack(dlist *pl,void(*pf)(info e));
void TraverseAsQueue(dlist *pl,void(*pf)(info e));
int isEmpty(dlist *pl);
int isFull(dlist *pl);
int listSize(dlist *pl);



#endif // DLIST_H_INCLUDED
