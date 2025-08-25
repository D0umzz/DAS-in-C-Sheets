#include <stdio.h>
#include <stdlib.h>
#include  "list.h"

void CreateList (List *pl)
{
    pl->size=0;
}
int ListEmpty (List *pl)
{
    return pl->size=0;
}
int ListFull (List *pl)
{
    return pl->size==MAXLIST;
}
int ListSize (List *pl)
{
    return pl->size;
}
void DestroyList (List *pl)
{
    pl->size=0;
}
void InsertList (int p, list_entry e, List *pl)
{
    if (p < 0 || p > pl->size) {
        return;
    }
    for(int i=pl->size-1;i>=p;i--)
        pl->Lentry[i+1]=pl->Lentry[i];
    pl->Lentry[p]=e;
    pl->size++;
}
void DeleteList (int p, list_entry *pe, List *pl)
{
    if (p < 0 || p >= pl->size) {
        return;
    }
    *pe=pl->Lentry[p];
    for(int i=p;i<pl->size-1;i++)
        pl->Lentry[i]=pl->Lentry[i+1];
    pl->size--;
}
void TraverseList(List *pl, void (*Visit)(list_entry))
{
    for(int i=0; i<pl->size; i++)
        (*Visit)(pl->Lentry[i]);
}
void RetrieveList(int p , list_entry *pe, List *pl)
{
    *pe=pl->Lentry[p];
}
void ReplaceList (int p, list_entry e, List *pl)
{
    pl->Lentry[p]=e;
}
