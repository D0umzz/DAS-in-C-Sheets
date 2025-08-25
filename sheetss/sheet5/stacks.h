#ifndef STACKS_H_INCLUDED
#define STACKS_H_INCLUDED

#include "../common/global.h"

typedef struct stacknode{
    struct stacknode *next;
    element_type entry;
}Stacknode;
typedef struct stack{
    Stacknode *top;
    int size;
}Stack;

void create_Stack(Stack *ps);
int StackFull(Stack *ps);
int StackEmpty(Stack *ps);
int Push(element_type e,Stack *ps);
void Pop(element_type *pe,Stack *ps);
///////////////////////////////////////////////
void Travers_Stack(Stack *ps, void(*pf)(int,char *));
int stacksize(Stack *ps);
void clearStack(Stack *ps);

#endif // STACKS_H_INCLUDED
