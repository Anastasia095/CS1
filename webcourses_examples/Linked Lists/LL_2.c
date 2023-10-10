
// This program demomstrates how to insert to the head or the tail using a
// linked list with a pointer to both head and tail.

// Includes
#include <stdio.h>
#include <stdlib.h>

// Aliases
typedef struct Node Node;
typedef struct List List;

// The linked list structure
struct List
{
    Node * head;
    Node * tail;
};

// The node structure
struct Node
{
    Node * next;
    int data;
};

// Function to create a node with a given data value
Node * createNode(int data)
{
    // Create a Node dynamically
    Node * res = (Node *) malloc(sizeof(Node));

    // Initialize the values in the node
    res->data = data;
    res->next = NULL;

    // Return the resulting node
    return res;
}

// Function to add a node with the value data at the beginning of a given list
void insertHead(List * my_list, int data)
{
    // Create the new node
    Node * newNode = createNode(data);

    // Have the new node point to the head of the list
    newNode->next = my_list->head;

    // Have the head of the list point to the new head
    my_list->head = newNode;
    
    // if the tail was null
    if (my_list->tail == NULL)
    {
        // Point the tail to the new node, because the list is no longer empty
        my_list->tail = newNode;
    }
}

// Function to add a node with the value data at the end of a given list
void insertTail(List * my_list, int data)
{
    // Create a new node
    Node * newNode = createNode(data);

    // Check if the list is non-empty
    if (my_list->tail != NULL)
    {
        // The old tail should have the next pointer refer to the new node
        my_list->tail->next = newNode;
    }
    else
    {
        // The head must be the new list since the list is no longer empty
        my_list->head = newNode;
    }

    // Set the tail of the list to the new node
    my_list->tail = newNode;
}

// Function to check if a list is empty
int isEmpty(List * my_list) 
{
    // Return if the head is NULL or not.
    // The head is NULL if and only if the list is empty
    return (my_list->head == NULL);
}

// Function to delete the first node of the list
void deleteHead(List * my_list)
{
    // No list?
    if (my_list == NULL) return;

    // Empty list check
    if (my_list->head == NULL) return; 

    // Store the old head address
    Node * oldHead = my_list->head;

    // Point to the new head
    my_list->head = my_list->head->next;

    // Satisfy the invariant of head/tail agreement
    if (my_list->head == NULL)
        my_list->tail = NULL;

    // Free the old node
    free(oldHead);
}

// Function to remove all the nodes from the list
void cleanList(List * my_list) 
{
    // Loop until all nodes are gone
    while (!isEmpty(my_list))
    {
        // Remove some node from the list
        deleteHead(my_list);
    }
}

// Function to print the contents of the list
void printList(List * my_list)
{
    // Track a node through the list
    Node * cur = my_list->head;

    // Loop to the end of the list
    while (cur != NULL)
    {
        // Print the list
        printf("%d -> ", cur->data);
        
        // Move to the next node
        cur = cur->next;
    }

    // Print the NULL at the end of the list
    printf("NULL\n");
}

// The main function
int main() 
{
    // The list
    List my_list;

    // Make the list empty
    my_list.head = my_list.tail = NULL;

    // Add a million 3's to the linked list
    for (int i = 0; i < 1000000; i++) 
    {
        insertTail(&my_list, 3);
    }

    // Print the list
    printList(&my_list);

    // Remove the allocated memory
    cleanList(&my_list);

    // Exit the program
    return 0;
}
