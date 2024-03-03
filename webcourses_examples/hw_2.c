// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUES 12

// Struct Aliases
typedef struct Customer Customer;
typedef struct Node Node;
typedef struct Queue Queue;
typedef struct QueueArr QueueArr;
typedef struct Booth Booth;


// Struct Definitions
//create a struct that stores information about a customer (name, number of tickets, linen umber, and arrival time).
struct Customer {
    char *name;
    int nt; //number of tickets
    int q;  //line number
    int t;  //arrival time
    int checkout_t;
};

//You must create a node struct for a linked list of customers. This struct should have a pointer to a customer struct, and a pointer to a node struct.
struct Node {
    Node * nxt;
    //data
    Customer * cus;
};
//You must create a struct to store a queue of customers. This struct should have two pointers – one to the front of the queue and one to the back, AND an integer field to store the size of the queue
struct Queue {
    Node * head, * tail;
    int size;
};

struct QueueArr {
    //the array of queues
    Queue * array[13];
};
int empty(Queue * q){
    if (q-> size == 0){
        return 0;
    } else {
        return 1;
    }
}
int queueSize(Queue * q){
    return q->size;
}


// using ASCII to get place in alphabet
int getQueue(char * name){
    char letter = name[0];
    int position;
    position = letter - 'A';

    return position;
}
int * getNotEmpty(QueueArr * list){
    
    int * notEmpty = (int *)calloc(MAX_QUEUES, sizeof(int));
    if (notEmpty == NULL){
        printf("Memory allocation failed \n");
        exit(1);
    }

    int k = 0;
    for(int i = 0; i < MAX_QUEUES; i++){
        // printf("test #%d %d\n", i, list[0].array[i]->size );
        
        if(empty(list[0].array[i]) == 1){
            // printf("test k #%d \n", k);
            notEmpty[k] = i; //get indexes of all none empty elements
            k++;
        }
    }
    if (k > 0) {
        notEmpty[k] = -1;
    }

    return notEmpty;
}
int lowNotEmpty(QueueArr * list){

    if (list == NULL) {
        // list is not initialized or is NULL.
        return -1;
    }
    //TODO: first nonempty queue (size > 0) with the least number of customers across all of the queues.
    int notEmpty[MAX_QUEUES];
    int k = 0;
    for(int i = 0; i < MAX_QUEUES; i++){
        // list->array[i] != NULL && 
        if(queueSize(list->array[i])> 0){
            notEmpty[k] = i; //get indexes of all not empty elements
            k++;
        }
    }
    if(k == 0){
        return 0;
    }
    //get lowest
    int min = list->array[notEmpty[0]]->size; // Initialize min with the first element
    int index = 0;

    for (int i = 1; i < k; i++) {
        if (list->array[notEmpty[i]]->size < min) {
            // Update min if a smaller element is found
            min = list->array[notEmpty[i]]->size; 
            index = i;
        }
    }

    //return index of the element of QueueArr that points to the queue with the smallest size
    return notEmpty[index];
}

Queue * createQueue() 
{   // allocate memory for a new queue and return the new queue
    Queue * res = (Queue *) malloc(sizeof(Queue));
    res->head = res->tail = NULL;
    res->size = 0;
    return res;
}

// create a function that can create a customer using dynamic memory allocation, fill out the customer and then return the customer.
Customer * createCustomer(QueueArr * list, char *name, int nt, int t)
{
    Customer * cus_address;
    cus_address = (Customer *) malloc(sizeof(Customer));
    cus_address->name = strdup(name);
    cus_address->nt = nt;
    //The processing time (in seconds) of a customer is calculated by 30 + number of tickets * 5.
    cus_address->checkout_t = 30 + (nt * 5) + t;
    //calculate place in queue
    int p = getQueue(name);
    // printf("P %d\n", p);
    if(p % 13 == 0){
        if(lowNotEmpty(list) == -1){
            // printf("P %d\n", -1);
            cus_address->q = 0; 
        } else {
            //  printf("P ELSE %d\n", lowNotEmpty(list));
            cus_address->q = lowNotEmpty(list); 
        }
    
    } else {
    cus_address->q = (p % 13) - 1;
    // printf("# %d\n", cus_address->q);

    //check if queue exist
    // if (list->array[cus_address->q] == NULL) {
    //     Queue *newQueue = createQueue();
    //     list->array[cus_address->q] = newQueue;
    // }
    }
    cus_address->t = t;

    return cus_address;

}

Node * createNode(Customer * cus)
{   // allocate memory for a new node in your list and
    // fill the node with the data passed into our createNode function
    Node * res = (Node *) malloc(sizeof(Node));
    //pointer to customer
    res->cus = cus;
    res->nxt = NULL;
    return res;
}
void insertTail(Queue * l, Customer * cus) 
{   
    if (!l) return; // if the list doesnt exist, return 
    
    Node * r = createNode(cus); // create a node with passed in value
    if (l->tail) 
    {
        l->tail->nxt = r; // add the new node to our old tail's next
        l->tail = r;      // update the list's tail to point to the new tail
    } else 
    {
        l->tail = l->head = r; // if list was empty, set the new node to the tail AND head
    }
}
void removeHead(Queue * l) 
{
    if (!l || !l->head) return; // if there is no list or no list head, then stop! or segfault
    
    if (l->head == l->tail)  // if the head and tail are the same node
    {
        free(l->head);   // free the head, which effectively also removes the tail
        l->head = l->tail = NULL; // update the list to tell us we no longer have head or tail
        return;
    }

    Node * newHead = l->head->nxt; // set cur head's next to be the new head
    free(l->head);     // now we can free our old head
    l->head = newHead; // have list's head point to our newHead
}

void dequeue(Queue * q) 
{ 
    if (q)
        removeHead(q); // so if our queue exists, we call to remove the head
}

void enqueue(Queue * q, Customer * cus) 
{ 
    if (q){
        insertTail(q, cus); // so if a queue exists, insert the new value at the end of it
        q->size++;
    }

}

Customer * front(Queue * q) 
{
    return q->head->cus; // return the data inside the head of the list
}

void deleteQueue(Queue * l) 
{
    while (l->head) removeHead(l); // while list has a head, we will call the removeHead function
    free(l); // we will free the list after all it's contents are removed, so we dont leak memory
}

//pass in array of queues
void checkout(QueueArr * queues, int index) {

    if (queues[0].array[index] == NULL) {
        printf("Something is wroing in checkout");
    return;
    }

    Queue *q = queues[0].array[index];
    for (int i = 0; i < q->size; i++) {
        Customer *cus = front(q);
        printf("%s from line %d checks out at time %d\n", cus->name, cus->q + 1, cus->checkout_t);
        dequeue(q);
        
    }
}


int main(){
    int n = 0;  //n (n ≤ 500,000), the number of customers purchasing tickets
    int b = 0;  //b (b ≤ 12), the number booths operating on that day
    int nt = 0; //positive integer, nt (0 < nt ≤ 500), representing the number of tickets the customer is buying
    int t = 0;  //unique positive integer, t (t ≤ 10^9), representing the time, in seconds
    int k = 0;  // number of queues
    int distribution = 0;
    int mod = 0;
    char name[51];
    int * activeQueues;

    scanf("%d %d", &n, &b);
    int booths[b];
    QueueArr Qarray; // Array of structs to keep track of queues

    for (int i = 0; i < 13; i++) {
        Qarray.array[i] = createQueue();
    }
    for (int i = 0; i < n; i++){
        scanf("%s %d %d", name, &nt,&t);
        Customer * cur = createCustomer(&Qarray, name, nt, t);
        // Enqueue customer, pass pointer to Queue customer was assigned to and pointer to a customer
        enqueue(Qarray.array[cur->q], cur);
    }

    activeQueues = getNotEmpty(&Qarray);
    while (activeQueues[k] != -1) {
        k++;
    }
    
    // K queues split amongst b Booths [k/b] 
    // printf("k: %d\n", k);
    distribution = k/b;
    // printf("distribution: %d\n", distribution);
    mod = k % b;
    // printf("mod: %d\n", mod);
    int size = 0;

    for(int i = 0; i < b; i++){
        if (i < mod){
            booths[i] = distribution + 1;
        } else {
            booths[i] = distribution;
        }

    }
    int counter = 0;
    int temp = 0;


    for(int i = 0; i < b; i++){
        printf("\nBooth %d\n", i + 1);
        counter += temp;
        for (int k = 0; k < booths[i]; k++){
            checkout(&Qarray, activeQueues[temp]);
            temp++;
        }
    }

    return 0;
}