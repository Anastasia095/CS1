
// Example program of a linked list

#include <stdio.h>
#include <stdlib.h>

// Aliases
typedef struct Node Node;
typedef struct LL LL;

// Node struct (pieces of the list)
struct Node {
    int data;
    Node * next;
};

// Linked List struct (container of the list)
struct LL {
    Node * head;
    int num_nodes;
};

// function to insert a node with some given data
// into a given list as the head node
void headInsertion(LL * list, int data) {
    // Create the node
    Node * newNode = (Node *)
                  malloc(sizeof(Node));

    // Initailize the memory for the node
    newNode->data = data;
    newNode->next = list->head;

    // Point the head to the correct node
    list->head = newNode;

    // Adjust the number of nodes in the list
    list->num_nodes++;
}

// Function to insert a node with some given data
// into a given list as the tail of the list
void tailInsertion(LL * list, int data) {
    // Create the node
    Node * newNode = (Node *)
                  malloc(sizeof(Node));
    
    // Initialize the values of the node
    newNode->data = data;
    newNode->next = NULL;

    // Try to find
    Node * oldTail = list->head;
    if (oldTail == NULL) {
        list->head = newNode;
        list->num_nodes++;
        return;
    }
    
    // Loop until the oldTail is the tail
    while (oldTail->next != NULL) {
        oldTail = oldTail->next;
    }

    // old tail is old tail
    oldTail->next = newNode;
    list->num_nodes++;
}

void printList(LL list) {
    Node * cur = list.head;

    printf("You have %d nodes\n", list.num_nodes);

    // Make sure to stop when hitting
    // NULL
    while (cur != NULL) {
        // Print the value out
        printf("%d -> ", cur->data);

        // Moving to the next location
        cur = cur->next;
    }

    printf("NULL\n");
}

void cleanList(LL list) {
    Node * curNode = list.head;
    for (int i = 0; i < list.num_nodes; i++) {
        Node * nextNode = curNode->next;
        free(curNode);
        curNode = nextNode;
    }
}

int main() {
    LL list;

    // initialize the list
    list.head = NULL;
    list.num_nodes = 0;

/*
    headInsertion(&list, 3);
    headInsertion(&list, 1);
    headInsertion(&list, 4);
    headInsertion(&list, 1);
    headInsertion(&list, 5);
*/
    for (int i = 0; i < 1000000; i++) {
        tailInsertion(&list, 3);
    }

    // Print the list
    printList(list);

    // Remove List (clean up any memory)
    cleanList(list);
    return 0;
}
