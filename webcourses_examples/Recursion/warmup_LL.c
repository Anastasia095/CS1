
// Program to demonstrate a recursive version of a linked list

// Headers
#include <stdio.h>
#include <stdlib.h>

// Struct and alias
typedef struct Node Node;
struct Node {
    Node * next;
    int data;
};

// Create node function (NOT RECURSIVE)
Node * createNode(int data) {
    Node * res = (Node *) malloc(sizeof(Node));
    res->data = data;
    res->next = NULL;
    return res;
}

// NOTE: Return the head of the list from every function

// Function to insert a nodes as the head of a linked list
// (NOT RECURSIVE)
Node * insertHead(Node * oldHead, int data) {
    Node * newHead = createNode(data);
    newHead->next = oldHead;
    return newHead;
}

// Function to insert a node as the tail of the list
// (RECURSIVE)
Node * insertTail(Node * oldHead, int data) {
    // BASE CASE: Node is the head and the tail
    if (oldHead == NULL) return createNode(data);

    // RECURSIVE CASE: There is some existing node
    oldHead->next = insertTail(oldHead->next, data);
    
    // Return whatever the original head was
    return oldHead;
}

// Function to print the contents of a list
// (NOT RECURSIVE; iterative)
void printList(Node * head) {
    Node * cur = head;
    while (cur) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// Function to remove the last node of a list
// (RECURSIVE)
Node * removeTail(Node * oldHead) {
    // BASE CASE: Empty list
    if (oldHead == NULL) {
        // List stays empty
        return NULL;
    }

    // BASE CASE: Single Node
    if (oldHead->next == NULL) {
        // Remove the node
        free(oldHead);

        // Make the head be an empty list
        oldHead = NULL;
    } else {
        // Recursive Case: More than 1 node
        oldHead->next = removeTail(oldHead->next);
    }

    // The head of the list did not change
    return oldHead;
}

// Function to remove all the nodes of a list
// (ITERATIVE)
void cleanList(Node * head) {
    // Iterate over and remove all nodes from the end
    while(head) {
        head = removeTail(head);
        printList(head);
    }
}

// The main function
int main() {
    Node * head;
    head = NULL; // the list is empty

    // Insert nodes randomly either at front or end
    for (int i = 0; i < 10; i++) {
        if (rand() % 2 == 0)
            head = insertHead(head, i);
        else
            head = insertTail(head, i);
        printList(head);
    }

    // Remove memory
    cleanList(head);

    // Exit program
    return 0;
}
