#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INSERTS 70
#define MAX 6
#define DOUBLY

typedef struct Node Node;

struct Node {
    Node *next;
    int value;
#ifdef DOUBLY
    Node *prev;
#endif
};

Node *insertFront(Node *head, int value);
Node *removeAll(int value, Node *head);
void printFwd(Node *head);

int main() {
    Node *head = NULL;
    int i;

    // Insert randoms
    for (i = 0; i < INSERTS; i++) {
        head = insertFront(head, rand() % (MAX + 1));
    }

    // Print the original list
    printFwd(head);

    // Remove all the values in several passes
    for (i = 0; i < (MAX + 1); i++) {

        // Remove all the nodes of value 1
        head = removeAll(i, head);

        // Print the updated list
        printFwd(head);
    }

    return 0;
}

Node *removeAll(int value, Node *head) {
    Node *newHead = head;
    Node *prevNode;
    Node *tmp;

    // Remove from newHead while the newHead is bad
    while (newHead != NULL && newHead->value == value) {
        // Store the node to delete
        tmp = newHead;

        // Update the head pointer
        newHead = newHead->next;
#ifdef DOUBLY
        if (newHead != NULL) {
            newHead->prev = NULL;
        }
#endif
        // Free the node to delete
        free(tmp);
        tmp = NULL;

        // Start the previous to the node under inspection at the head
        // The head was not a bad node
        prevNode = newHead;

        // Remove from non-head nodes
        while (prevNode != NULL && prevNode->next != NULL) {
            // Check if the previous node is previous to a bad value
            if (prevNode->next->value == value) {
                // Get the node to delete
                tmp = prevNode->next;

                // Modify the pointer(s) to the node to be deleted
                prevNode->next = tmp->next;
#ifdef DOUBLY
                if (tmp->next != NULL) {
                    tmp->next->prev = prevNode;
                }
#endif

                // Free this node that contains the bad value
                free(tmp);
                tmp = NULL;
            } else {
                // Skip this node
                prevNode = prevNode->next;
            }
        }
    }
    // Return the updated head
    return newHead;
}

// Standard insert at the front
Node *insertFront(Node *head, int value) {
    Node *newHead = (Node *)calloc(1, sizeof(Node));
    newHead->value = value;
    newHead->next = head;
#ifdef DOUBLY
    if (head != NULL)
        head->prev = newHead;
#endif
    return newHead;
}

// Standard print in the forward direction
void printFwd(Node *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", head->value);
    printFwd(head->next);
}
