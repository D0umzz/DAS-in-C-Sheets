#include <stdio.h>
#include <stdlib.h>
#include "stacks.h"


void create_Stack(Stack *ps)
{
    ps->top=NULL;
    ps->size=0;
}
int StackFull(Stack *ps)
{
    return 0;
}
int StackEmpty(Stack *ps)
{
    return ps->top==NULL;
}
int Push(element_type e,Stack *ps)
{
    Stacknode *pn=(Stacknode*)malloc(sizeof(Stacknode));
    if(!pn)
        return 0;
    else
    {
        pn->entry=e;
        pn->next=ps->top;
        ps->top=pn;
        ps->size++;
        return 1;
    }
 }
void Pop(element_type *pe,Stack *ps)
{
    Stacknode *pn;
    *pe=ps->top->entry;
    pn=ps->top;
    ps->top=ps->top->next;
    free(pn);
    ps->size--;
}
///////////////////////////////////////////////
void Travers_Stack(Stack *ps, void(*pf)(int,char *))
{
    Stacknode *pn;
    pn=ps->top;
    while(pn)
    {
        (*pf)(pn->entry.id,pn->entry.name);
        pn=pn->next;
    }
}
int stacksize(Stack *ps)
{
    return ps->size;
}
void clearStack(Stack *ps)
{
    Stacknode *pn;
    pn=ps->top;
    while(pn)
    {
        pn=pn->next;
        free(ps->top);
        ps->top=pn;
    }
    ps->size=0;
}

