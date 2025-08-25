#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

 void createStack(Stack *ps)
 {
     ps->top=0;
 }
int isStackFull(Stack *ps)
{
    return(ps->top>=MAX);
}
int isStackEmpty(Stack *ps)
{
    return(ps->top==0);
}
void push(stack_entry e,Stack *ps)
{
    if(isStackFull(ps))
    {
            printf("Error:stack overflow");
    }
    else
    {
            ps->entry[ps->top++]=e;
    }

}
void pop(stack_entry *pe,Stack *ps)
{
    if(isStackEmpty(ps))
    {
            printf("Error:stack is empty");
    }
    else
    {
            *pe=ps->entry[--ps->top];
    }
}
void TraversStack(Stack *ps, void(*pf)(stack_entry))
{
    for (int i = ps->top - 1; i >= 0; i--) {
        pf(ps->entry[i]);
    }
}

int stack_size(Stack *ps)
{
    /*
    Pre-condition:
        stack initialized by createStack
    Post-condition:
        Returns the number of elements currently in the stack
    */
    return (ps->top);
}
//sheet2
stack_entry FirstInStack(Stack *ps)
{
    return ps->entry[0];
}
stack_entry LastInStack(Stack *ps)
{
    return ps->entry[ps->top-1];
}
void DestroyStack(Stack *ps)
{
    ps->top=0;
}
void CopyStackToAnother(Stack *ps1 ,Stack *ps2)
{
    if(isStackEmpty(ps1)){
        printf("Error the first stack is empty");
    }
    for(int i=0;i<ps1->top;i++){
        ps2->entry[i]=ps1->entry[i];
    }
    ps2->top=ps1->top;
}
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
int isBalanced(char *expr)
{
    Stack ps;
    createStack(&ps);
    for(int i=0;expr[i];i++)
    {
        char c=expr[i];
        if(c == '(' || c == '{' || c == '[')
           {push(c,&ps);}
            else if(c == ')' || c == '}' || c == ']')
            {
                char topChar;
                pop(&topChar, &ps);
                if (!isMatchingPair(topChar, c))
                {return 0;}
            }
    }
    return ps.top==0;
}
