#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void createQueue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
int isQueueFull(Queue *pq)
{
    return pq->size==MAX;
}
int isQueueEmpty(Queue *pq)
{
    return pq->size==0;
}
void Append(queue_entry e,Queue *pq)
{
    pq->rear=(pq->rear+1)%MAX;
    pq->q_entry[pq->rear]=e;
    pq->size++;
}
void Serve(queue_entry *pe,Queue *pq)
{
    *pe=pq->q_entry[pq->front];
    pq->front=(pq->front+1)%MAX;
    pq->size--;
}
void TraversQueue(Queue *pq, void(*pf)(queue_entry))
{
    int pos,s;
    for(pos=pq->front,s=0;s<pq->size;s++)
    {
        (*pf)(pq->q_entry[pos]);
        pos = (pos + 1) % MAX;
    }
}
int queue_size(Queue *pq)
{
    /*
    Pre-condition:
        Queue initialized by createQueue
    Post-condition:
        Returns the number of elements currently in the queue
    */
    return pq->size;
}
queue_entry LastInQueue(Queue *pq)
{
    return pq->q_entry[pq->rear];
}
queue_entry FirstInQueue(Queue *pq)
{
    return pq->q_entry[pq->front];
}
void DistroyQueue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void CopyQueueToAnother(Queue *pq1 ,Queue *pq2)
{
    if (pq2->size + pq1->size <= MAX)
        {
        int pos=pq1->front;
        for(int s=0;s<pq1->size;s++)
        {
            pq2->rear=(pq2->rear+1)%MAX;
            pq2->q_entry[pq2->rear] = pq1->q_entry[pos];
            pq2->size++;
            pos = (pos + 1) % MAX;
        }
        }
}
/////////////////////////
//RENAMED TO MATCH MY CODE
void TraverseQueue1(Queue* q, void (*f)(queue_entry *)){
    int i, siz;
    for(i=q->front, siz=0; siz<q->size; siz++){
        (*f)(&(q->q_entry[i]));
        i=(i+1)%MAX;
    }
}
int TraverseQueue2(Queue * q, int (*f)(queue_entry *, queue_entry),queue_entry e){
    int i, s;
    int r=0;
    for(i=q->front, s=0; s<q->size; s++){
    r+=(*f)(&(q->q_entry[i]),e);
    i=(i+1)%MAX;
}
return r;
}
