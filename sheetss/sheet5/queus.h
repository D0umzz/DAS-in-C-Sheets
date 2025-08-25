#ifndef QUEUS_H_INCLUDED
#define QUEUS_H_INCLUDED

#include "../common/global.h"


typedef struct queuenode{
    struct queuenode *next;
    element_type entry;
}Queuenode;
typedef struct queue{
    Queuenode *front;
    Queuenode *rear;
    int size;
}Queue;

void createQueue(Queue *pq);
int isQueueFull(Queue *pq);
int isQueueEmpty(Queue *pq);
int Append(element_type e,Queue *pq);
void Serve(element_type *pe,Queue *pq);
////////////////////////////
void TraversQueue(Queue *pq, void(*pf)(int,char *));
int queue_size(Queue *pq);

#endif // QUEUS_H_INCLUDED
