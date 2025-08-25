#ifndef CALLS_H_INCLUDED
#define CALLS_H_INCLUDED

typedef enum { DATA, VOICE, EMERGENCY } CallType;

typedef struct dataCall{
    int numPackets;
} DataCall;

typedef struct voiceCall{
    int callerID;
    int isRoaming;
} VoiceCall;

typedef struct call {
    CallType type;

    int callerNumber;
    union {
        DataCall data;
        VoiceCall voice;
    } details;

    struct call* next;
    struct call* prev;
} Call;

typedef struct callqueue {
    Call* head;
    Call* tail;
    int Size;
} CallQueue;

void createCallQueue(CallQueue *pcq);
int appendDataCall(Call *c, CallQueue *pcq);
int appendVoiceCall(Call *c, CallQueue *pcq);
int appendEmergencyCall(Call *c, CallQueue *pcq);
int appendCall(CallType ctype, Call *c, CallQueue *pcq);
int serveCall(CallQueue *pcq);
void dismissLeastPriority(CallQueue *pcq);
void traversecalls(CallQueue *pcq,void (*pf)(Call *c));

#endif // CALLS_H_INCLUDED
