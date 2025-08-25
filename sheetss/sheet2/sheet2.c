#include <stdio.h>
#include <stdlib.h>
#include "../common/stack.h"

void display(stack_entry e) {
    printf("e is: %c\n", e);
}

int main() {
    Stack s;
    createStack(&s);
    push('a',&s);
    push('b',&s);
    push('c',&s);
    push('d',&s);
    push('e',&s);
    printf("the stack we are working on :\n");
    TraversStack(&s,&display);
    //question n1 return the first entry to the stack
    printf("##Q1##\n");
    stack_entry q1=FirstInStack(&s);
    printf("the first item entered the stack is: %c\n",q1);
    //---------------------------
    //question n2
    printf("##Q2##\n");
    stack_entry q2=LastInStack(&s);
    printf("the last item entered the stack is: %c\n",q2);
    //---------------------------
    //question n3
    printf("##Q3##\n");
    Stack q3;
    createStack(&q3);
    push('a',&q3);
    push('b',&q3);
    push('c',&q3);
    push('d',&q3);
    push('e',&q3);
    DestroyStack(&q3);
    printf("the stack 'q3' was destroyed\n");
    TraversStack(&q3,&display);
    //---------------------------
    //question n4
    //copping stack s our main "s" one to q4
    printf("##Q4##\n");
    Stack q4;
    createStack(&q4);
    CopyStackToAnother(&s,&q4);
    printf("stack'q4': \n");
    TraversStack(&q4,&display);
    //---------------------------
    //question n5
    //returning the size of our main stack "s"
    printf("##Q5##\n");
    int size=stack_size(&s);
    printf("the size of stack 's' is: %d\n",size);
    //---------------------------
    //question n6
    //the first entry to the stack 'user level'
    printf("##Q6##\n");
    stack_entry q6='\0';
    Stack sq6;
    createStack(&sq6);
    push('A',&sq6);
    push('b',&sq6);
    push('c',&sq6);
    push('d',&sq6);
    push('e',&sq6);
    while(!isStackEmpty(&sq6)){
        pop(&q6,&sq6);
    }
    printf("the first entry to the stack'sq6' is: %c\n",q6);
    //---------------------------
    //question n7
    //a copy from last entry 'user level'
    printf("##Q7##\n");
    stack_entry q7='\0';
    Stack sq7;
    createStack(&sq7);
    push('a',&sq7);
    push('b',&sq7);
    push('c',&sq7);
    push('d',&sq7);
    push('E',&sq7);
    pop(&q7,&sq7);
    printf("the last entry to stack 'sq7'is: %c\n",q7);
    push(q7,&sq7);
    //---------------------------
    //question n8
    //destroying the stack 'user level'
    printf("##Q8##\n");
    printf("destroying the stack 'sq7'\n");
    TraversStack(&sq7,&display);
    while(!isStackEmpty(&sq7)){
        pop(&q7,&sq7);
    }
    printf("the stack 'sq7' was destroyed\n");
    TraversStack(&sq7,&display);
    //---------------------------
    //question n9
    //copy a stack 's'to another'sq9' 'user level'
    printf("##Q9##\n");
    Stack sq9;
    Stack temp;
    createStack(&sq9);
    createStack(&sq9);
    stack_entry q9='\0';
    while(!isStackEmpty(&s))
    {
        pop(&q9,&s);
        push(q9,&temp);
    }
    while(!isStackEmpty(&temp))
    {
        pop(&q9,&temp);
        push(q9,&s);
        push(q9,&sq9);
    }
    printf("the copy: \n");
    TraversStack(&sq9,&display);
    //question n10
    //size  'user level' test
    printf("##Q10##\n");
    int counter=0;
        while(!isStackEmpty(&sq9))
    {
        pop(&q9,&sq9);
        counter++;
    }
    printf("the number of elements of stack 'sq9'is: %d\n",counter);
    //question n11
    //traverse 'user level'
    printf("##Q11##\n");
    Stack temp2;
    createStack(&temp2);
    stack_entry q10='\0';
    while(!isStackEmpty(&s))
    {
        pop(&q10,&s);
        push(q10,&temp2);
        printf(" e is: %c\n",q10);
    }
    while(!isStackEmpty(&temp2))
    {
        pop(&q10,&temp2);
        push(q10,&s);
    }
    printf("Also our main stack 's' managed to survive this sheet \n");
    TraversStack(&s,&display);

    return 0;
}
