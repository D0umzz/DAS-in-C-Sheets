#include <stdio.h>
#include <stdlib.h>
#include "../common/stack.h"

int main() {
    stack_entry item;
    Stack stack;
    createStack(&stack);
    int choice;

    createStack(&stack);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Read an element then Push it\n");
        printf("2. Pop an element then display it\n");
        printf("3. The stack size\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            if (!isStackFull(&stack)) {
                printf("Enter a character to push: ");
                scanf("%c", &item);
                getchar();
                push(item, &stack);
            } else {
                printf("Stack is full.\n");
            }
        } else if (choice == 2) {
            if (!isStackEmpty(&stack)) {
                pop(&item, &stack);
                printf("Popped: %c\n", item);
            } else {
                printf("Stack is empty.\n");
            }
        } else if (choice == 3) {
            int size = stack_size(&stack);
            printf("The stack size = %d\n", size);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    printf("???????????????????????????????????????????????????\n");
    printf("???????????????????????????????????????????????????\n");

    /*
    display the content of the stack in the user level
    without losing its content
    */
    Stack stack2;
    createStack(&stack2);
    Stack temp_stack;
    createStack(&temp_stack);
    stack_entry e;
    push('1', &stack2);
    push('2', &stack2);
    push('3', &stack2);
    push('4', &stack2);
    push('5', &stack2);
    while(!isStackEmpty(&stack2)){
        pop(&e,&stack2);
        push(e,&temp_stack);
    }
    while(!isStackEmpty(&temp_stack)){
        pop(&e,&temp_stack);
        printf("%c \n",e);
        push(e,&stack2);
    }

    return 0;
}
