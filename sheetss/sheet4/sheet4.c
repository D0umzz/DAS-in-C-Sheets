#include <stdio.h>
#include <stdlib.h>
#include "../common/queueL.h"
#include "../common/stackL.h"
#include "../common/queue.h"

void View(queueL_entry e)
{
    printf("e is: %d\n",e);
}
void Mrgd(int i)
{
    printf("merged qe is: %d\n",i);
}
//////////////////////////////////
void print(queue_entry *e){
    printf("%d\n", *e);
}
int count(queue_entry *e1, queue_entry e2){
    return((*e1)== e2);
}
int replaceMoreThan(queue_entry *e1, queue_entry e2){
    if ((*e1)>e2) {
            *e1 = e2;
    return 1;
    } else return 0;
}


int main(){
    //question n1
    //Merge two queue(section code*10+group code)
    printf("##Q1##\n");
    QueueL qs,qg;
    int m;
    createQueueL(&qs);
    createQueueL(&qg);
    for(int i=1;i<=4;i++)
    {
        AppendL(10+i,&qs);
        AppendL(i,&qg);
    }
    printf("section codes\n");
    TraversQueueL(&qs,&View);
    printf("group codes\n");
    TraversQueueL(&qg,&View);
    printf("Merged codes\n");
    Merge(&qs,&qg,&m,&Mrgd);
    //---------------------------
    //question n2
    //Creating scodes &gcodes
    printf("##Q2##\n");
    int e;
    StackL ids,ss,sg;
    create_Stack(&ids);
    create_Stack(&ss);
    create_Stack(&sg);
        for(int i=20240101;i<=20240106;i++)
    {
        Push(i,&ids);
    }
    printf("IDS : \n");
    Travers_Stack(&ids,&View);
    while(!StackEmpty(&ids)){
        Pop(&e,&ids);
        Push(e/10,&ss);
        Push(e%10,&sg);
    }
    printf("SECTION CODES : \n");
    Travers_Stack(&ss,&View);
    printf("GROUP CODES : \n");
    Travers_Stack(&sg,&View);
    //---------------------------
    //question n3
    //
    printf("##Q3##\n");
    //copy code to imp then trace
    Queue q;
    int i;
    createQueue(&q);
    for(i=0; i<=4; i++)
        Append(i*5,&q);
    for(i=1; i<=5; i++)
        Append(i*5,&q);
    printf("printing the 'q' elements:\n");
    TraverseQueue1(&q, &print);
    printf("checks for (17) in 'q':\n");
    printf("%d\n",TraverseQueue2(&q, &count, 17));
    printf("replace numbers >17 with(17) in 'q':\n");
    printf("%d\n",TraverseQueue2(&q, &replaceMoreThan, 17));
    printf("checks for (17) in 'q':\n");
    printf("%d\n",TraverseQueue2(&q, &count, 17));
    printf("printing the 'q' elements:\n");
    TraverseQueue1(&q, &print);
    return 0;
}
