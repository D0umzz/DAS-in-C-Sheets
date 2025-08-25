#include <stdio.h>
#include <stdlib.h>
#include "calls.h"

void printCall(Call* c) {
    if (c->type == DATA) {
        printf("DATA Call: Caller %d, Packets %d\n", c->callerNumber, c->details.data.numPackets);
    } else if (c->type == VOICE) {
        printf("VOICE Call: Caller %d, Roaming %d\n", c->callerNumber, c->details.voice.isRoaming);
    } else {
        printf("EMERGENCY Call: Caller %d\n", c->callerNumber);
    }
}

int main() {
    CallQueue queue;
    createCallQueue(&queue);

    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Data Call coming.\n");
        printf("2. Voice Call coming.\n");
        printf("3. Emergency Call coming.\n");
        printf("4. Serve a call.\n");
        printf("5. Dismiss calls with least priority.\n");
        printf("6. Exit.\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 6) break;

        Call tempCall;

        switch (choice) {
            case 1: // Data Call
                tempCall.type = DATA;
                printf("Enter caller number: ");
                scanf("%d", &tempCall.callerNumber);
                printf("Enter number of packets: ");
                scanf("%d", &tempCall.details.data.numPackets);
                if (appendCall(DATA, &tempCall, &queue))
                    printf("Data call appended.\n");
                else
                    printf("Failed to append Data call.\n");
                break;

            case 2: // Voice Call
                tempCall.type = VOICE;
                printf("Enter caller number: ");
                scanf("%d", &tempCall.callerNumber);
                printf("Is roaming? (1 = yes, 0 = no): ");
                scanf("%d", &tempCall.details.voice.isRoaming);
                if (appendCall(VOICE, &tempCall, &queue))
                    printf("Voice call appended.\n");
                else
                    printf("Failed to append Voice call.\n");
                break;

            case 3: //Emergency Call
                tempCall.type = EMERGENCY;
                printf("Enter caller number: ");
                scanf("%d", &tempCall.callerNumber);
                if (appendCall(EMERGENCY, &tempCall, &queue))
                    printf("Emergency call appended.\n");
                else
                    printf("Failed to append Emergency call.\n");
                break;

            case 4: //Serve call
                if (serveCall(&queue))
                    printf("Served one call from queue.\n");
                else
                    printf("Queue is empty.\n");
                break;

            case 5: //Dismiss least priority
                dismissLeastPriority(&queue);
                printf("Dismissed least priority calls.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

        //Show current queue
        printf("\nCurrent Calls in Queue (%d):\n", queue.Size);
        traversecalls(&queue, printCall);
    }

    printf("Exiting...\n");

    while (serveCall(&queue)) {}

    return 0;
}
