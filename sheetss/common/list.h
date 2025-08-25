#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define MAXLIST 20

typedef int list_entry;

typedef struct list{
    int size;
    list_entry  Lentry[MAXLIST];
}List;

void CreateList (List *pl);
int ListEmpty (List *pl);
int ListFull (List *pl);
int ListSize (List *pl);
void DestroyList (List *pl);
void InsertList (int p, list_entry e, List *pl);
void DeleteList (int p, list_entry *pe, List *);
void TraverseList(List *pl, void (*Visit)(list_entry));
void RetrieveList(int p , list_entry *pe, List *pl);
void ReplaceList (int p, list_entry e, List *pl);


#endif // LIST_H_INCLUDED
