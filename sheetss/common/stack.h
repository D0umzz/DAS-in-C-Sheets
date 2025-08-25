#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAX 20
typedef char stack_entry;

typedef struct stack{
    int top;
    stack_entry entry[MAX];
}Stack;

void createStack(Stack *ps);
int isStackFull(Stack *ps);
int isStackEmpty(Stack *ps);
void push(stack_entry e,Stack *ps);
void pop(stack_entry *pe,Stack *ps);
///////////////////////////////////////////////
void TraversStack(Stack *ps, void(*pf)(stack_entry));
int stack_size(Stack *ps);
stack_entry FirstInStack(Stack *ps);
stack_entry LastInStack(Stack *ps);
void DestroyStack(Stack *ps);
void CopyStackToAnother(Stack *ps1 ,Stack *ps2);
//////////////////////////////////////////////
int isMatchingPair(char open, char close);
int isBalanced(char *expr);

#endif // STACK_H_INCLUDED
