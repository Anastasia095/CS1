
// A program that quickly removes first and last values of the list

// Include headers
#include <stdio.h>
#include <stdlib.h>

// Aliases for the node and list
typedef struct Node Node;
typedef struct List List;

// Struct defintions
struct Node 
{
    Node * nxt, * prv;
    int data;
};
struct List 
{
    Node * head, * tail;
};

// Function to remove the head of the list
void removeHead(List * lst) {
    // Check if the list is not there or empty
    if (lst == NULL || lst->head == NULL)
        return;

    // 1 node case check
    if (lst->head == lst->tail) 
    {
        free(lst->head);
        lst->head = lst->tail = NULL;
        return;
    }

    // Make the head of the list the next node
    lst->head = lst->head->nxt;

    free(lst->head->prv); // remove old head
    lst->head->prv = NULL; // Nothing is before head
}

// Function to remove the tail of the list
void removeTail(List * lst) {
    // Check if teh list is not there or empty
    if (lst == NULL || lst->tail == NULL)
        return;

    // 1 node case check
    if (lst->head == lst->tail) 
    {
        free(lst->tail);
        lst->head = lst->tail = NULL;
        return;
    }

    // Make the tail of the list the node prior to the tail
    lst->tail = lst->tail->prv;
    
    free(lst->tail->nxt); // remove old tail
    lst->tail->nxt = NULL; // Nothing is before head
}

// Function to create a node
Node * createNode(int data) 
{
    // Allocate memory for the node
    Node * res = (Node *) malloc(sizeof(Node));

    // Initialize the values of the node
    res->data = data;
    res->nxt = res->prv = NULL;

    // Return the node
    return res;
}

// Function to add a node the head of the list
void insertHead(List * lst, int data) 
{
    // Check if the list of nodes
    if (lst == NULL) return;
    
    // Empty list case
    if (lst->head == NULL) 
    {
        // The head and tail are the newly created node
        lst->head = lst->tail = createNode(data);
        return;
    }

    // Connect the node to the list
    lst->head->prv = createNode(data);
    lst->head->prv->nxt = lst->head;

    // Point to the new head
    lst->head = lst->head->prv;
}

// Add a node to the end of the list
void insertTail(List * lst, int data) 
{
    // Check if the list is not there
    if (lst == NULL) return;
    
    // Empty list case
    if (lst->head == NULL) 
    {
        // Set the head and the tail to the created node
        lst->head = lst->tail = createNode(data);
        return;
    }

    // Connect the node to the list
    lst->tail->nxt = createNode(data);
    lst->tail->nxt->prv = lst->tail;

    // Point to the new tail
    lst->tail = lst->tail->nxt;
}

// Function to print a list
void printList(List * lst) 
{
    Node * cur = lst->head;
    while (cur != NULL) {
        printf("%d <-> ", cur->data);
        cur = cur->nxt;
    }
    printf("NULL\n");
}

// The main function
int main() 
{
    // Make an empty list
    List lst;
    lst.head = lst.tail = NULL;
    
    // Add values to the beginning and ending of the list
    for (int i = 0; i < 10; i++) 
    {
        // Check if the number is odd
        if (i % 2) 
        {
            insertTail(&lst, i);
        }
        else
        {
            insertHead(&lst, i);
        }

        // Print after each insertion
        printList(&lst);
    }

    // Remove values from the beginning and ending of the list
    for (int i = 0; i < 12; i++) 
    {
        // Check if the value is odd
        if (i % 2) 
        {
            removeTail(&lst);
        } 
        else
        {
            removeHead(&lst);
        }

        // Print after each insertion
        printList(&lst);
    }

    // Exit program
    return 0; 
}

