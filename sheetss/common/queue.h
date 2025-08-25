#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define MAX 20

typedef int queue_entry;

typedef struct queue
{
    int front;
    int rear;
    int size;
    queue_entry q_entry[MAX];
}Queue;

void createQueue(Queue *pq);
int isQueueFull(Queue *pq);
int isQueueEmpty(Queue *pq);
void Append(queue_entry e,Queue *pq);
void Serve(queue_entry *pe,Queue *pq);
////////////////////////////
void TraversQueue(Queue *pq, void(*pf)(queue_entry));
int queue_size(Queue *pq);
queue_entry LastInQueue(Queue *pq);
queue_entry FirstInQueue(Queue *pq);
void DistroyQueue(Queue *pq);
void CopyQueueToAnother(Queue *pq1 ,Queue *pq2);
///////////////////////////////
void TraverseQueue1(Queue* q, void (*f)(queue_entry *));
int TraverseQueue2(Queue * q, int (*f)(queue_entry *, queue_entry),queue_entry e);
#endif // QUEUE_H_INCLUDED
