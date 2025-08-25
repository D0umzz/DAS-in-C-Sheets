#ifndef STACKL_H_INCLUDED
#define STACKL_H_INCLUDED

typedef int stackL_entry;

typedef struct stacknode{
    struct stacknode *next;
    stackL_entry entry;
}Stacknode;
typedef struct stack{
    Stacknode *top;
    int size;
}StackL;

void create_Stack(StackL *ps);
int StackFull(StackL *ps);
int StackEmpty(StackL *ps);
int Push(stackL_entry e,StackL *ps);
int Pop(stackL_entry *pe,StackL *ps);
///////////////////////////////////////////////
void Travers_Stack(StackL *ps, void(*pf)(stackL_entry));
int stacksize(StackL *ps);
void clearStack(StackL *ps);
///////////////
stackL_entry FirstInStackL(StackL *ps);
stackL_entry LastInStackL(StackL *ps);
void CopyStack(StackL *s1,StackL *s2);
////////////////
int isMatchingPair(char open, char close);
int isBalanced(char *expr);

#endif // STACKL_H_INCLUDED
