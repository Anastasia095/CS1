// 09/08/23
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct LL LL;

struct Node
{
    /* data */
    int data;
    Node * next;
};

struct LL
{
    /* data */
    Node * head;
    int num_nodes;
};

void headInsertion(LL * list, int data){
    Node * newNode = (Node *) malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->num_nodes++;
}

void printList(LL list){
    Node * cur = list.head;

    // printf("%d")
    while (cur != NULL){
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

 void tailInsertion(LL * list, int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data;
    newNode->next = NULL;

    Node * oldTail = list->head;
    if(oldTail == NULL){
        list->head = newNode;
        list->num_nodes++;
        return;
    }
    //loop till old tail is the tail
    while(oldTail->next != NULL) {
        oldTail = oldTail->next;
    }

    // old tail is old tail
    oldTail->next = newNode;
    list->num_nodes++;
 } 

 void cleanList(LL list){
    Node * curNode = list.head;
    for (int i = 0; i < list.num_nodes; i++){
        free(curNode);
        curNode = curNode->next;
    }
 }


int main(){

    LL list;

    list.head = NULL;
    list.num_nodes = 0;

    // headInsertion(&list, 3);
    // headInsertion(&list, 1);
    // headInsertion(&list, 4);
    // headInsertion(&list, 1);
    // headInsertion(&list, 5);

    tailInsertion(&list, 3);
    tailInsertion(&list, 1);
    tailInsertion(&list, 4);
    tailInsertion(&list, 1);
    tailInsertion(&list, 5);

    printList(list);
    cleanList(list);
    
    
    return 0;
}