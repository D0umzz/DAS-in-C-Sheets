#ifndef QUEUEL_H_INCLUDED
#define QUEUEL_H_INCLUDED

typedef int queueL_entry;

typedef struct queuenode{
    struct queuenode *next;
    queueL_entry entry;
}Queuenode;
typedef struct queuel{
    Queuenode *front;
    Queuenode *rear;
    int size;
}QueueL;

void createQueueL(QueueL *pq);
int isQueueLFull(QueueL *pq);
int isQueueLEmpty(QueueL *pq);
int AppendL(queueL_entry e,QueueL *pq);
void ServeL(queueL_entry *pe,QueueL *pq);
////////////////////////////
void TraversQueueL(QueueL *pq, void(*pf)(queueL_entry));
int queueL_size(QueueL *pq);
////////////////////////////
void Merge( QueueL *sec ,QueueL *grp , int *m , void (*pf)(int));
queueL_entry LastInQueueL(QueueL *pq);
queueL_entry FirstInQueueL(QueueL *pq);
void DistroyQueueL(QueueL *pq);
void CopyQueueL(QueueL *q1,QueueL *q2);
#endif // QUEUEL_H_INCLUDED
