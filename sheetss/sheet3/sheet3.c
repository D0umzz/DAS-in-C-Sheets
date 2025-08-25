#include <stdio.h>
#include <stdlib.h>
#include "../common/stack.h"
#include "../common/queue.h"

void displayQ(queue_entry e) {
    printf("qe is: %d\n", e);
}

int main(){
    //question n1
    printf("##Q1##\n");
    char expr[] = "{[()]}";
    if (isBalanced(expr)) {
        printf("Balanced \n");
    } else {
        printf("Not Balanced \n");
    }
    //---------------------------
    //question n2
    //REDO sheet '1'
    printf("##Q2##\n");
    Queue q;
    createQueue(&q);
    queue_entry qe;
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
            if (!isQueueFull(&q)) {
                printf("Enter a character to Append: ");
                scanf("%d", &qe);
                Append(qe, &q);
            } else {
                printf("Queue is full.\n");
            }
        } else if (choice == 2) {
            if (!isQueueEmpty(&q)) {
                Serve(&qe, &q);
                printf("Served: %d\n", qe);
            } else {
                printf("Queue is empty.\n");
            }
        } else if (choice == 3) {
            int size = queue_size(&q);
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
    queue_entry qe2;
    Queue q2,tmpq;
    createQueue(&q2);
    createQueue(&tmpq);
    Append(1,&q2);
    Append(2,&q2);
    Append(3,&q2);
    Append(4,&q2);
    printf("the elements of 'q2':\n");
    while(!isQueueEmpty(&q2))
    {
        Serve(&qe2,&q2);
        printf("hi :%d\n",qe2);
        Append(qe2,&tmpq);
    }
    while(!isQueueEmpty(&tmpq))
    {
        Serve(&qe2,&tmpq);
        Append(qe2,&q2);
    }
    printf("'q2' managed to servive our 'user level' code:\n");
    TraversQueue(&q2,&displayQ);
    //---------------------------
    //question n3
    //return the last e in implementation level
    printf("##Q3##\n");
    //our mains are Me and MQ
    queue_entry Me;
    Queue MQ;
    createQueue(&MQ);
    Append(11,&MQ);
    Append(12,&MQ);
    Append(13,&MQ);
    Append(14,&MQ);
    queue_entry Leq=LastInQueue(&MQ);
    printf("The last element in our main Queue'MQ' (on the rear)  is :%d\n",Leq);
    //---------------------------
    //question n4
    //return the First e in implementation level
    printf("##Q4##\n");
    queue_entry Feq=FirstInQueue(&MQ);
    printf("The First element in our main Queue'MQ' (on the Front)  is :%d\n",Feq);
    //---------------------------
    //question n5
    //destroy in implementation level
    printf("##Q5##\n");
    printf("q2:\n");
    TraversQueue(&q2,&displayQ);
    printf("destroying q2:\n");
    DistroyQueue(&q2);
    TraversQueue(&q2,&displayQ);
    //---------------------------
    //question n6
    //destroy in implementation level
    printf("##Q6##\n");
    printf("filling 'q2' again with our main 'MQ':\n");
    CopyQueueToAnother(&MQ,&q2);
    printf("the copy 'q2'\n");
    TraversQueue(&q2,&displayQ);
    printf("the Main 'MQ'\n");
    TraversQueue(&MQ,&displayQ);
    //---------------------------
    //question n7
    //size implementation level
    printf("##Q7##\n");
    int sz=queue_size(&MQ);
    printf("The size of our main 'MQ' is:%d\n",sz);
    //---------------------------
    //question n8
    //return the last e in user level
    printf("##Q8##\n");
    Queue tmp;
    createQueue(&tmp);
    while(!isQueueEmpty(&q2)){
        Serve(&Me,&q2);
        Append(Me,&tmp);
    }
    printf("The last element in Queue'q2' (on the rear)  is :%d\n",Me);
    while(!isQueueEmpty(&tmp)){
        Serve(&Me,&tmp);
        Append(Me,&q2);
    }
    //---------------------------
    //question n9
    //return the First e in user level
    printf("##Q9##\n");
    Serve(&Me,&q2);
    printf("The First element in Queue'q2' (on the Front)  is :%d\n",Me);
    Append(Me,&tmp);
    while(!isQueueEmpty(&q2)){
        Serve(&Me,&q2);
        Append(Me,&tmp);
    }
    while(!isQueueEmpty(&tmp)){
        Serve(&Me,&tmp);
        Append(Me,&q2);
    }
    printf("The queue 'q2' low-key managed to survive : \n");
    TraversQueue(&q2,&displayQ);
    //---------------------------
    //question n10
    //destroying queue user level
    printf("##Q10##\n");
    while(!isQueueEmpty(&q2)){
        Serve(&Me,&q2);
    }
    printf("destroying q2:\n");
    TraversQueue(&q2,&displayQ);
    //---------------------------
    //question n11
    //coping one queue 'MQ'to another'q2' user level
    printf("##Q11##\n");
    while(!isQueueEmpty(&MQ)){
        Serve(&Me,&MQ);
        Append(Me,&tmp);
    }
    while(!isQueueEmpty(&tmp)){
        Serve(&Me,&tmp);
        Append(Me,&q2);
        Append(Me,&MQ);
    }
    printf("The copy 'q2':\n");
    TraversQueue(&q2,&displayQ);
    printf("The Main 'MQ':\n");
    TraversQueue(&MQ,&displayQ);
    //---------------------------
    //question n12
    //size user level
    printf("##Q12##\n");
    int counterr;
    while(!isQueueEmpty(&q2)){
        Serve(&Me,&q2);
        Append(Me,&tmp);
        counterr++;
    }
    while(!isQueueEmpty(&tmp)){
        Serve(&Me,&tmp);
        Append(Me,&q2);
    }
    printf("The size of the queue:%d\n",counterr);
    printf("the counting process also not harming the queue 'q2':\n");
    TraversQueue(&q2,&displayQ);
    return 0;
}
