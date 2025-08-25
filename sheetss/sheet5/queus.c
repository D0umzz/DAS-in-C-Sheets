#include <stdio.h>
#include <stdlib.h>
#include "queus.h"

void createQueue(Queue *pq)
{
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;
}
int isQueueFull(Queue *pq)
{
    return 0;
}
int isQueueEmpty(Queue *pq)
{
    return pq->size==0;
}
int Append(element_type e,Queue *pq)
{
    Queuenode *qn=(Queuenode*)malloc(sizeof(Queuenode));
    if(!qn)
        return 0;
    else
    {
        qn->entry=e;
        qn->next=NULL;
        if(!pq->rear)
            pq->front=qn;
        else
            pq->rear->next=qn;
        pq->rear=qn;
        pq->size++;
        return 1;
    }
}
void Serve(element_type *pe, Queue *pq) {
    Queuenode *qn = pq->front;
    *pe = qn->entry;
    pq->front = pq->front->next;

    if (pq->front == NULL)
        pq->rear = NULL;

    free(qn);
    pq->size--;
}
////////////////////////////
void TraversQueue(Queue *pq, void(*pf)(int,char *))
{
    Queuenode *qn;
    for(qn=pq->front;qn;qn=qn->next)
    {
        (*pf)(qn->entry.id,qn->entry.name);
    }
}
int queue_size(Queue *pq)
{
    return pq->size;
}


