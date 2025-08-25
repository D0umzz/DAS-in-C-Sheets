#include <stdio.h>
#include "../common/dlist.h"


void printInfo(info e) {
    printf("Key: %d, Value: %d\n", e.key, e.val);
}

// Function to delete a node by key
int deleteByKey(int key, info *pe, dlist *pl) {
    if (!pl->head) {
        printf("List is empty\n");
        return 0;
    }

    Node *curr = pl->head;
    int pos = 0;
    while (curr) {
        if (curr->data.key == key) {
            return deleteNodeAtPos(pos, pe, pl);
        }
        curr = curr->next;
        pos++;
    }

    printf("Key %d not found\n", key);
    return 0;
}

int main() {
    dlist myList;
    info temp, deleted;

    create(&myList);

    // Inserting different elements
    for (int i = 1; i <= 5; i++) {
        temp.key = i;
        temp.val = i * 100;
        insertNode(temp, &myList);
    }

    printf("List after insertion:\n");
    TraverseAsQueue(&myList, printInfo);

    // Deleting key = 2
    printf("\nDeleting element with key = 2:\n");
    if (deleteByKey(2, &deleted, &myList)) {
        printf("Deleted element: Key: %d, Value: %d\n", deleted.key, deleted.val);
    }

    printf("\nList after deletion:\n");
    TraverseAsQueue(&myList, printInfo);

    // Destroying list
    destroy(&myList);
    printf("\nList destroyed.\n");
    printf("Is list empty? %s\n", isEmpty(&myList) ? "Yes" : "No");

    return 0;
}
