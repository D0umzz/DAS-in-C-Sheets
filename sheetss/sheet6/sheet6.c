#include <stdio.h>
#include <stdlib.h>
#include "../common/list.h"
#include "../common/stackL.h"
#include "../common/queueL.h"

void display(stackL_entry e){
    printf("E is :%c \n",e);
}
void displayq(queueL_entry e){
    printf("E is :%d \n",e);
}

int main()
{
    //---------------------------
    //question n1
    //build Array based list implementation
    printf("##Q1##\n");
    printf("Done\n");
    //---------------------------
    //question n2
    //build linked based Stack implementation
    printf("##Q2##\n");
    printf("Done");
    //---------------------------
    //question n3
    //REDO Sheet 2 in linked based stack
    printf("##Q3##\n");
    StackL s;
    create_Stack(&s);
    Push('a',&s);
    Push('b',&s);
    Push('c',&s);
    Push('d',&s);
    Push('e',&s);
    printf("the stack we are working on :\n");
    Travers_Stack(&s,&display);
    //return the first entry to the stack
    printf("##Q3q1##\n");
    stackL_entry q1=FirstInStackL(&s);
    printf("the first item entered the stack is: %c\n",q1);
    //---------------------------
    printf("##Q3q2##\n");
    stackL_entry q2=LastInStackL(&s);
    printf("the last item entered the stack is: %c\n",q2);
    //---------------------------
    printf("##Q3q3##\n");
    StackL q3;
    create_Stack(&q3);
    Push('a',&q3);
    Push('b',&q3);
    Push('c',&q3);
    Push('d',&q3);
    Push('e',&q3);
    clearStack(&q3);
    printf("the stack 'q3' was destroyed\n");
    Travers_Stack(&q3,&display);
    //---------------------------
    //copping stack s our main "s" one to q4
    printf("##Q3q4##\n");
    StackL q4;
    create_Stack(&q4);
    CopyStack(&s,&q4);
    printf("stack'q4': \n");
    Travers_Stack(&q4,&display);
    //---------------------------
    //returning the size of our main stack "s"
    printf("##Q3q5##\n");
    int size=stacksize(&s);
    printf("the size of stack 's' is: %d\n",size);
    //---------------------------
    //the first entry to the stack 'user level'
    printf("##Q3q6##\n");
    stackL_entry q6='\0';
    StackL sq6;
    create_Stack(&sq6);
    Push('A',&sq6);
    Push('b',&sq6);
    Push('c',&sq6);
    Push('d',&sq6);
    Push('e',&sq6);
    while(!StackEmpty(&sq6)){
        Pop(&q6,&sq6);
    }
    printf("the first entry to the stack'sq6' is: %c\n",q6);
    //---------------------------
    //a copy from last entry 'user level'
    printf("##Q3q7##\n");
    stackL_entry q7='\0';
    StackL sq7;
    create_Stack(&sq7);
    Push('a',&sq7);
    Push('b',&sq7);
    Push('c',&sq7);
    Push('d',&sq7);
    Push('E',&sq7);
    Pop(&q7,&sq7);
    printf("the last entry to stack 'sq7'is: %c\n",q7);
    Push(q7,&sq7);
    //---------------------------
    //destroying the stack 'user level'
    printf("##Q3q8##\n");
    printf("destroying the stack 'sq7'\n");
    Travers_Stack(&sq7,&display);
    while(!StackEmpty(&sq7)){
        Pop(&q7,&sq7);
    }
    printf("the stack 'sq7' was destroyed\n");
    Travers_Stack(&sq7,&display);
    //---------------------------
    //copy a stack 's'to another'sq9' 'user level'
    printf("##Q3q9##\n");
    StackL sq9;
    StackL temp;
    create_Stack(&sq9);
    create_Stack(&temp);
    stackL_entry q9='\0';
    while(!StackEmpty(&s))
    {
        Pop(&q9,&s);
        Push(q9,&temp);
    }
    while(!StackEmpty(&temp))
    {
        Pop(&q9,&temp);
        Push(q9,&s);
        Push(q9,&sq9);
    }
    printf("the copy: \n");
    Travers_Stack(&sq9,&display);
    //size  'user level' test
    printf("##Q3q10##\n");
    int counter=0;
        while(!StackEmpty(&sq9))
    {
        Pop(&q9,&sq9);
        counter++;
    }
    printf("the number of elements of stack 'sq9'is: %d\n",counter);
    //traverse 'user level'
    printf("##Q3q11##\n");
    StackL temp2;
    create_Stack(&temp2);
    stackL_entry q10='\0';
    while(!StackEmpty(&s))
    {
        Pop(&q10,&s);
        Push(q10,&temp2);
        printf(" e is: %c\n",q10);
    }
    while(!StackEmpty(&temp2))
    {
        Pop(&q10,&temp2);
        Push(q10,&s);
    }
    printf("Also our main stack 's' managed to survive this sheet \n");
    Travers_Stack(&s,&display);
    //---------------------------
    //question n4
    //build linked based Queue implementation
    printf("##Q4##\n");
    printf("Done\n");
    //---------------------------
    //question n5
    //REDO sheet 3 LinkedStackADT.
    printf("##Q5q1##\n");
    char *testExprs[] = {"{[()]}", "((()))", "({[)", "(", NULL};
        for (int i = 0; testExprs[i]; i++) {
                printf("Expression: %s => ", testExprs[i]);
        if (isBalanced(testExprs[i])) {
                printf("Balanced\n");
        } else {
                printf("Not Balanced\n");
    }}
    //---------------------------
    //REDO sheet '1'
    printf("##Q5q2##\n");
    QueueL q;
    createQueueL(&q);
    queueL_entry qe;
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Read an element then Append it\n");
        printf("2. Serve an element then display it\n");
        printf("3. The Queue size\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            if (!isQueueLFull(&q)) {
                printf("Enter an integer to Append: ");
                scanf("%d", &qe);
                AppendL(qe, &q);
            } else {
                printf("Queue is full.\n");
            }
        } else if (choice == 2) {
            if (!isQueueLEmpty(&q)) {
                ServeL(&qe, &q);
                printf("Served: %d\n", qe);
            } else {
                printf("Queue is empty.\n");
            }
        } else if (choice == 3) {
            int size = queueL_size(&q);
            printf("The Queue size = %d\n", size);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
        /*
    display the content of the stack in the user level
    without losing its content
    */
    queueL_entry qe2;
    QueueL q22,tmpq;
    createQueueL(&q22);
    createQueueL(&tmpq);
    AppendL(1,&q22);
    AppendL(2,&q22);
    AppendL(3,&q22);
    AppendL(4,&q22);
    printf("the elements of 'q22':\n");
    while(!isQueueLEmpty(&q22))
    {
        ServeL(&qe2,&q22);
        printf("hi :%d\n",qe2);
        AppendL(qe2,&tmpq);
    }
    while(!isQueueLEmpty(&tmpq))
    {
        ServeL(&qe2,&tmpq);
        AppendL(qe2,&q22);
    }
    printf("'q2' managed to servive our 'user level' code:\n");
    TraversQueueL(&q22,&displayq);
    //---------------------------
    //return the last e in implementation level
    printf("##Q5q3##\n");
    //our mains are Me and MQ
    queueL_entry Me;
    QueueL MQ;
    createQueueL(&MQ);
    AppendL(11,&MQ);
    AppendL(12,&MQ);
    AppendL(13,&MQ);
    AppendL(14,&MQ);
    queueL_entry Leq=LastInQueueL(&MQ);
    printf("The last element in our main Queue'MQ' (on the rear)  is :%d\n",Leq);
    //---------------------------
    //return the First e in implementation level
    printf("##Q5q4##\n");
    queueL_entry Feq=FirstInQueueL(&MQ);
    printf("The First element in our main Queue'MQ' (on the Front)  is :%d\n",Feq);
    //---------------------------
    //destroy in implementation level
    printf("##Q5q5##\n");
    printf("q22:\n");
    TraversQueueL(&q22,&displayq);
    printf("destroying q22:\n");
    DistroyQueueL(&q22);
    TraversQueueL(&q22,&displayq);
    //---------------------------
    //destroy in implementation level
    printf("##Q5q6##\n");
    printf("filling 'q22' again with our main 'MQ':\n");
    CopyQueueL(&MQ,&q22);
    printf("the copy 'q22'\n");
    TraversQueueL(&q22,&displayq);
    printf("the Main 'MQ'\n");
    TraversQueueL(&MQ,&displayq);
    //---------------------------
    //size implementation level
    printf("##Q5q7##\n");
    int sz=queueL_size(&MQ);
    printf("The size of our main 'MQ' is:%d\n",sz);
    //---------------------------
    //return the last e in user level
    printf("##Q5q8##\n");
    QueueL tmp;
    createQueueL(&tmp);
    while(!isQueueLEmpty(&q22)){
        ServeL(&Me,&q22);
        AppendL(Me,&tmp);
    }
    printf("The last element in Queue'q22' (on the rear)  is :%d\n",Me);
    while(!isQueueLEmpty(&tmp)){
        ServeL(&Me,&tmp);
        AppendL(Me,&q22);
    }
    //---------------------------
    //return the First e in user level
    printf("##Q5q9##\n");
    ServeL(&Me,&q22);
    printf("The First element in Queue'q22' (on the Front)  is :%d\n",Me);
    AppendL(Me,&tmp);
    while(!isQueueLEmpty(&q22)){
        ServeL(&Me,&q22);
        AppendL(Me,&tmp);
    }
    while(!isQueueLEmpty(&tmp)){
        ServeL(&Me,&tmp);
        AppendL(Me,&q22);
    }
    printf("The queue 'q22' low-key managed to survive : \n");
    TraversQueueL(&q22,&displayq);
    //---------------------------
    //destroying queue user level
    printf("##Q5q10##\n");
    while(!isQueueLEmpty(&q22)){
        ServeL(&Me,&q22);
    }
    printf("destroying q22:\n");
    TraversQueueL(&q22,&displayq);
    //---------------------------
    //coping one queue 'MQ'to another'q2' user level
    printf("##Q5q11##\n");
    while(!isQueueLEmpty(&MQ)){
        ServeL(&Me,&MQ);
        AppendL(Me,&tmp);
    }
    while(!isQueueLEmpty(&tmp)){
        ServeL(&Me,&tmp);
        AppendL(Me,&q22);
        AppendL(Me,&MQ);
    }
    printf("The copy 'q22':\n");
    TraversQueueL(&q22,&displayq);
    printf("The Main 'MQ':\n");
    TraversQueueL(&MQ,&displayq);
    //---------------------------
    //size in user level
    printf("##Q5q12##\n");
    int counterr=0;
    while(!isQueueLEmpty(&q22)){
        ServeL(&Me,&q22);
        AppendL(Me,&tmp);
        counterr++;
    }
    while(!isQueueLEmpty(&tmp)){
        ServeL(&Me,&tmp);
        AppendL(Me,&q22);
    }
    printf("The size of the queue:%d\n",counterr);
    printf("the counting process also not harming the queue 'q22':\n");
    TraversQueueL(&q22,&displayq);

    return 0;
}
