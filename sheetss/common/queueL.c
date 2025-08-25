#include "queueL.h"
#include <stdio.h>
#include <stdlib.h>


void createQueueL(QueueL *pq)
{
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;
}
int isQueueLFull(QueueL *pq)
{
    return 0;
}
int isQueueLEmpty(QueueL *pq)
{
    return pq->size==0;
}
int AppendL(queueL_entry e,QueueL *pq)
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
void ServeL(queueL_entry *pe, QueueL *pq)
{
    if (isQueueLEmpty(pq)) {
        printf("queue underflow\n");
        return;
    }

    Queuenode *qn = pq->front;
    *pe = qn->entry;
    pq->front = pq->front->next;
    free(qn);
    pq->size--;

    if (pq->size == 0)
        pq->rear = NULL;
}
////////////////////////////
void TraversQueueL(QueueL *pq, void(*pf)(queueL_entry))
{
    Queuenode *qn;
    for(qn=pq->front;qn;qn=qn->next)
    {
        (*pf)(qn->entry);
    }
}
int queueL_size(QueueL *pq)
{
    return pq->size;
}
///////////////////////////
void Merge( QueueL *sec,QueueL *grp,int *m,void (*pf)(int))
{
    Queuenode *ps =sec->front;
    Queuenode *pg=grp->front;
    for ( ;ps && pg;ps=ps->next,pg=pg->next)
    {
        m=((ps->entry *10)+pg->entry);
        (*pf)(m);
    }
}
queueL_entry LastInQueueL(QueueL *pq)
{
    if(!pq->front)
        return;
    return pq->rear->entry;
}
queueL_entry FirstInQueueL(QueueL *pq)
{
    if(!pq->front)
        return;
    return pq->front->entry;
}
void DistroyQueueL(QueueL *pq)
{
    while(pq->front)
    {
        pq->rear = pq->front->next;
        free(pq->front);
        pq->front = pq->rear;
    }
    pq->rear=NULL;
    pq->size=0;
}
void CopyQueueL(QueueL *q1,QueueL *q2)
{
    Queuenode *pn,*newnode;
    pn=q1->front;
    q2->front=q2->rear=NULL;
    q2->size=0;
        while(pn)
        {
            newnode=(Queuenode*)malloc(sizeof(Queuenode));
            if(!newnode)
            {
                printf("failed memory allocation");
                return;
            }
            newnode->entry=pn->entry;
            newnode->next=NULL;
            if (q2->rear == NULL)
            {
                q2->front = q2->rear = newnode;
            }
            else
            {
                q2->rear->next=newnode;
                q2->rear=newnode;
            }
            pn=pn->next;
        }
        q2->size=q1->size;

}




