#ifndef LISTL_H_INCLUDED
#define LISTL_H_INCLUDED

typedef int listL_entry;

typedef struct listnode{
    struct listnode *next;
    listL_entry Lentry;
}Listnode;
typedef struct listl{
    Listnode *head;
    int size;
}ListL;

void Create_List (ListL *pl);
int isListEmpty (ListL *pl);
int isListFull (ListL *pl);
int List_Size (ListL *pl);
void Destroy_List (ListL *pl);
int Insert_List (int p, listL_entry e, ListL *pl);
void Delete_List (int p, listL_entry *pe, ListL *);
void Traverse_List(ListL *pl, void (*Visit)(listL_entry));
void Retrieve_List(int p , listL_entry *pe, ListL *pl);
void Replace_List (int p, listL_entry e, ListL *pl);

#endif // LISTL_H_INCLUDED
