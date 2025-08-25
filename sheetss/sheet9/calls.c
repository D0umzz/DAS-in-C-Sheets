#include <stdio.h>
#include <stdlib.h>
#include "calls.h"

void createCallQueue(CallQueue *pcq)
{
    pcq->head=NULL;
    pcq->tail=NULL;
    pcq->Size=0;
}
int appendDataCall(Call *c, CallQueue *pcq) {
    Call* newCall = (Call*)malloc(sizeof(Call));
    if (!newCall) return 0;

    *newCall = *c;
    newCall->next = NULL;
    newCall->prev = NULL;

    if (pcq->head == NULL) {
        pcq->head = pcq->tail = newCall;
    } else {

        Call* curr = pcq->tail;
        while (curr && curr->type != DATA && curr->type != VOICE) {
            curr = curr->prev;
        }

        if (curr == NULL) {
            newCall->next = pcq->head;
            pcq->head->prev = newCall;
            pcq->head = newCall;
        } else {
            newCall->next = curr->next;
            newCall->prev = curr;

            if (curr->next)
                curr->next->prev = newCall;
            else
                pcq->tail = newCall;

            curr->next = newCall;
        }
    }

    pcq->Size++;
    return 1;
}
int appendVoiceCall(Call *c, CallQueue *pcq) {
    Call* newCall = (Call*)malloc(sizeof(Call));
    if (!newCall) return 0;

    *newCall = *c;
    newCall->next = NULL;
    newCall->prev = NULL;

    if (pcq->head == NULL) {
        pcq->head = pcq->tail = newCall;
    } else {
        Call* curr = pcq->tail;
        while (curr && curr->type != VOICE && curr->type != EMERGENCY) {
            curr = curr->prev;
        }

        if (curr == NULL) {
            newCall->next = pcq->head;
            pcq->head->prev = newCall;
            pcq->head = newCall;
        } else {
            newCall->next = curr->next;
            newCall->prev = curr;

            if (curr->next)
                curr->next->prev = newCall;
            else
                pcq->tail = newCall;

            curr->next = newCall;
        }
    }

    pcq->Size++;
    return 1;
}
int appendEmergencyCall(Call *c, CallQueue *pcq) {
    Call* newCall = (Call*)malloc(sizeof(Call));
    if (!newCall) return 0;

    *newCall = *c;
    newCall->next = NULL;
    newCall->prev = NULL;

    if (pcq->head == NULL) {
        pcq->head = pcq->tail = newCall;
    } else {
        Call* curr = pcq->tail;
        while (curr && curr->type != EMERGENCY)
        {
            curr = curr->prev;
        }

        if (curr == NULL)
        {
            newCall->next = pcq->head;
            pcq->head->prev = newCall;
            pcq->head = newCall;
        } else {

            newCall->next = curr->next;
            newCall->prev = curr;

            if (curr->next)
                curr->next->prev = newCall;
            else
                pcq->tail = newCall;

            curr->next = newCall;
        }
    }

    pcq->Size++;
    return 1;
}
int appendCall(CallType ctype, Call *c, CallQueue *pcq) {
    c->type = ctype;

    if (ctype == DATA) {
        return appendDataCall(c, pcq);
    } else if (ctype == VOICE) {
        return appendVoiceCall(c, pcq);
    } else if (ctype == EMERGENCY) {
        return appendEmergencyCall(c, pcq);
    }

    return 0;
}
int serveCall(CallQueue *pcq) {
    if (pcq == NULL || pcq->head == NULL) {
        return 0;
    }

    Call* toServe = pcq->head;


    pcq->head = toServe->next;

    if (pcq->head == NULL) {

        pcq->tail = NULL;
    } else {
        pcq->head->prev = NULL;
    }

    free(toServe);
    pcq->Size--;

    return 1;
}
void dismissLeastPriority(CallQueue *pcq) {
    if (pcq == NULL || pcq->head == NULL) return;

    int dataExists = 0;
    for (Call* cur = pcq->head; cur != NULL; cur = cur->next) {
        if (cur->type == DATA) {
            dataExists = 1;
            break;
        }
    }

    CallType toDismiss = dataExists ? DATA : VOICE;

    Call* cur = pcq->head;
    while (cur != NULL) {
        Call* next = cur->next;
        if (cur->type == toDismiss) {
            if (cur->prev) cur->prev->next = cur->next;
            else pcq->head = cur->next;

            if (cur->next) cur->next->prev = cur->prev;
            else pcq->tail = cur->prev;

            free(cur);
            pcq->Size--;
        }
        cur = next;
    }
}
void traversecalls(CallQueue *pcq,void (*pf)(Call *c))
{
    Call *pn=pcq->head;
    while(pn)
    {
        (*pf)(pn);
        pn=pn->next;
    }
}
