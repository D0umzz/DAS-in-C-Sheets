#include <stdio.h>
#include <stdlib.h>
#include "stackL.h"


void create_Stack(StackL *ps)
{
    ps->top=NULL;
    ps->size=0;
}
int StackFull(StackL *ps)
{
    return 0;
}
int StackEmpty(StackL *ps)
{
    return ps->top==NULL;
}
int Push(stackL_entry e,StackL *ps)
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
int Pop(stackL_entry *pe, StackL *ps)
{
    if (StackEmpty(ps)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return 0;
    }

    Stacknode *pn = ps->top;
    *pe = pn->entry;
    ps->top = pn->next;
    free(pn);
    ps->size--;
    return 1;
}

///////////////////////////////////////////////
void Travers_Stack(StackL *ps, void(*pf)(stackL_entry))
{
    Stacknode *pn;
    pn=ps->top;
    while(pn)
    {
        (*pf)(pn->entry);
        pn=pn->next;
    }
}
int stacksize(StackL *ps)
{
    return ps->size;
}
void clearStack(StackL *ps)
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
stackL_entry FirstInStackL(StackL *ps)
{
    Stacknode *pn=ps->top;
    while(pn->next!=NULL){
            pn=pn->next;
    }
    return pn->entry;

}
stackL_entry LastInStackL(StackL *ps)
{
    return ps->top->entry;
}
void CopyStack(StackL *s1,StackL *s2)
{
    Stacknode *temp = s1->top;
    StackL tempStack;
    tempStack.top = NULL;
        while (temp) {
            Stacknode *newNode = (Stacknode*)malloc(sizeof(Stacknode));
            if (!newNode) {
                printf("Memory allocation failed.\n");
                return;
            }
            newNode->entry = temp->entry;
            newNode->next = tempStack.top;
            tempStack.top = newNode;
            temp = temp->next;
        }
        temp = tempStack.top;
        while (temp) {
            Stacknode *newNode = (Stacknode*)malloc(sizeof(Stacknode));
            if (!newNode) {
                printf("Memory allocation failed.\n");
                return;
            }
            newNode->entry = temp->entry;
            newNode->next = s2->top;
            s2->top = newNode;
            temp = temp->next;
            s2->size++;
        }
        while (tempStack.top) {
            Stacknode *toFree = tempStack.top;
            tempStack.top = tempStack.top->next;
            free(toFree);
        }
}
///////////////////////////
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char *expr) {
    StackL ps;
    create_Stack(&ps);

    for (int i = 0; expr[i]; i++) {
        char c = expr[i];

        if (c == '(' || c == '{' || c == '[') {
            Push(c, &ps);
        } else if (c == ')' || c == '}' || c == ']') {
            char topChar;

            if (!Pop(&topChar, &ps)) {
                return 0;
            }

            if (!isMatchingPair(topChar, c)) {
                return 0;
            }
        }
    }
    return StackEmpty(&ps);
}




