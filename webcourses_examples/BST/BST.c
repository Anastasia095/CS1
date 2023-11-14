
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node { 
    int value;
    Node * right;
    Node * left;
    // Node * parent;
};

Node * createNode(int value) {
    Node * ret = (Node *) malloc(sizeof(Node));
    ret->value = value;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

// Insert a node into a BST and return the resulting root
Node * insert(Node * root, int value) {
    // Base Case: empty tree
    if (root == NULL) {
        // Create the root and return it
        return createNode(value);
    }
    // Recursive
    if (root->value == value) {
        // value is already in the tree (exit)
        return root;
    }
    if (root->value > value) {
        // Root is bigger than the value
        // the value goes into the left side of the tree
        root->left = insert(root->left, value);
    } else {
        // Root is smaller than the value
        // The value goes into the right side (large values)
        root->right = insert(root->right, value);
    }

    // Return original root
    return root;
}

// Return 1 if the value is in the binary search tree
// Return 0 otherwise
int contains(Node * root, int value) {
    // Base Case: Empty tree case
    if (root == NULL) {
        return 0;
    }
    if (root->value == value) {
        return 1;
    }
    // Technically works but why???
    // return contains(root->right, value) + contains(root->left, value);
    if (root->value < value) {
        // the value is larger than the root
        return contains(root->right, value);
    }

    // The value must be smaller than the root
    return contains(root->left, value);
}

// Remove a value from a BST and return the resulting root of the tree
Node * remove(Node * root, value) {
    
}

int main() {
    Node * root = NULL;
    int N = 100000;
    for (int i = 0; i < N; i++) {
        // int value = rand() % N;
        int value = i;
        printf("Inserting %d...\n", value);
        root = insert(root, value);
    }

    for (int i = 0; i < N; i++) {
        if (contains(root, i)) {
            printf("%d was in the tree.\n", i);
        }
    }   
    return 0;
}
