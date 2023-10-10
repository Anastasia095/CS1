
// Program that implements and uses a stack (implemented using an LL)

// Header files
#include <stdio.h>
#include <stdlib.h>

// Struct aliases
typedef struct Node Node;
typedef struct List List;
typedef struct Stack Stack;

// Struct definitions
struct Node {
    int data;
    Node * next;
};
struct List {
    Node * head;
};
struct Stack {
    List * list;
};

// *** Prototypes ***
Node * createNode(int value);

List * createList();
void   insertHead(List * list, int value);
void   removeHead(List * list);

Stack * createStack();
void    pop(Stack * stk);
void    push(Stack * stk, int value);
int     top(Stack * stk);

// *** Functions ***

// Create a nodes function
Node * createNode(int value)
{
   Node * res = (Node *) malloc(sizeof(Node));
   res->data = value;
   res->next = NULL;
   return res;
}

// Create a list function
List * createList()
{
   List * res = (List *) malloc(sizeof(List));
   res->head = NULL;
   return res;  
}

// Function to add a node as the head of a list
void insertHead(List * list, int value)
{
   // No list???
   if(!list) return; 
      
   // Create the new nodes
   Node * newHead = createNode(value);

   // Pointer adjustments
   Node * oldHead = list->head;
   list->head = newHead;
   newHead->next = oldHead;
}

// Function to remove a node from the beginning of a list
void removeHead(List * list)
{
   // No or empty list cases
   if(!list) return;
   if(list->head == NULL) return;
 
   // Store the address of the nodes to be used
   Node * oldHead = list->head;
   Node * newHead = list->head->next;

   // Remove memory
   free(oldHead);

   // Adjust pointers
   list->head = newHead; 
}

// Function to create a stack dynamically
Stack * createStack()
{
   Stack * res = (Stack *) malloc(sizeof(Stack));
   res->list = createList();
   return res;
}

// Function to remove (most recent) values from the stack
void pop(Stack * stk)
{
   if (stk && stk->list)  
      removeHead(stk->list);
}

// Function to add values to the stack
void push(Stack * stk, int value)
{
   if (stk && stk->list)  
      insertHead(stk->list, value);
}

// Function to check the top of the stack
int top(Stack * stk)
{
   if(!stk || !stk->list || !stk->list->head) return 0;
   return stk->list->head->data;
}

// Function to evaluate an operation with some given operands
int eval(int fOp, int sOp, char operator)
{
    if (operator == '+') return fOp + sOp;
    if (operator == '-') return fOp - sOp;
    if (operator == '*') return fOp * sOp;
    if (operator == '/') return fOp / sOp;
    return 0;
}

// Check if a given string is a number
int isInt(char * str) 
{
    if (str[0] == '-' && str[1] == 0)
        return 0;
    if (str[0] == '-') return 1;
    if (str[0] <= '9' && str[0] >= '0')
        return 1;
    return 0;
}

// The main function
int main()
{
    Stack * stk = createStack();
    char str[1000 + 1];
    while (-1 != scanf("%s", str)) 
    {
        printf("%s\n", str); 
        if (isInt(str)) 
        {
            push(stk, atoi(str));
        }
        else 
        {
            int second = top(stk); pop(stk);
            int first = top(stk); pop(stk);
            push(stk, eval(first, second, str[0]));
        }
    }

    printf("The result is %d.\n", top(stk));
    
    // deleteStack(stk);


   return 0;
}
