#include <stdio.h>
#include <stdlib.h>
#include "listL.h"

void Create_List (ListL *pl)
{
    pl->head=NULL;
    pl->size=0;
}
int isListEmpty (ListL *pl)
{
    return pl->head==NULL;
}
int isListFull (ListL *pl)
{
    return 0;
}
int List_Size (ListL *pl)
{
    return pl->size;
}
void Destroy_List (ListL *pl)
{
    Listnode *pn;
    pn=pl->head;
    while(pn)
    {
        pn=pn->next;
        free(pl->head);
        pl->head=pn;
    }
    pl->size=0;
}
int Insert_List (int p, listL_entry e, ListL *pl)
{
    int i;
    Listnode *pn,*qn;
    if(pn=(Listnode*)malloc(sizeof(Listnode)))
    {
            pn->Lentry=e;
            pn->next=NULL;
    if (p==0)
    {
        pn->next=pl->head;
        pl->head=pn;
    }
    else
    {
        for(qn=pl->head ,i=0;i<p-1;i++)
            qn=qn->next;
        pn->next=qn->next;
        qn->next=pn;
    }
    pl->size++;
    return 1;
    }
    else return 0;
}
void Delete_List (int p, listL_entry *pe, ListL *pl)
{
    int i;
    Listnode *f,*x;
    if (p==0)
    {
        *pe=pl->head->Lentry;
        f=pl->head->next;
        free(pl->head);
        pl->head=f;
    }
    else{
        for(f=pl->head,i=0;i<p-1;i++)
            f=f->next;
        x=f->next;
        *pe=x->Lentry;
        f->next=x->next;
        free(x);
    }
    pl->size--;
}
void Traverse_List(ListL *pl, void (*Visit)(listL_entry))
{
    Listnode *pn;
    pn=pl->head;
    while(pn)
    {
        (*Visit)(pn->Lentry);
        pn=pn->next;
    }
}
void Retrieve_List(int p , listL_entry *pe, ListL *pl)
{
    int i;
    Listnode *pn;
    for(pn=pl->head,i=0;i<p;i++)
        pn=pn->next;
    *pe=pn->Lentry;
}
void Replace_List (int p, listL_entry e, ListL *pl)
{
    int i;
    Listnode *pn;
    for(pn=pl->head,i=0;i<p;i++)
            pn=pn->next;
    pn->Lentry=e;
}
