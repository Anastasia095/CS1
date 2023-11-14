#include
#include

typedef struct Node Node;

struct Node {
    Node * root;
    Node * left;
    Node * right;
    Node * parent;

    int value;
};

Node * createNode(int v){
    Node * res = (Node *) malloc(sizeof(Node));
    res->value = v;
    res->right = res->left = res->parent = NULL;
    return res;
}

Node * insert(Node * root, int v){
    if(root == NULL) return createNode(v); //empty tree
    if(root->value == v) return root; //no insert

    //check if the roots value is tpp small (go right)
    if(root->value < v) {
        root->right = insert(root-> right, v);
        //WHATS THIS?
        root->right->parent = root;
    }
    if(root->value > v) {
        root->left = insert(root->right, v);
        root->left->parent = root;
    }

    return root;
}
void rotateRight(){

    Node * parent = root->parent;
    Node * child = root->left;
    Node * grandChild = child->right;

    //top
    //connect parent child
    child->parent = parent;
    if(parent != NULL){
        if(parent->right == root)
            parent->right = child;
        else   
            parent->left = child;
        //mid
        child->right = root;
        root->parent = child;
        //bot
        //copnnect root to grandchild
        root->left = grandChild;
        grandChild->parent = root;
    }

}

void rotateLeft(Node * root){

    Node * parent = root->parent;
    Node * child = root->right;
    Node * grandChild = child->left;

    //top
    //connect parent child
    child->parent = parent;
    if(parent != NULL){
        if(parent->left == root)
            parent->left = child;
        else   
            parent->right = child;
        //mid
        child->left = root;
        root->parent = child;
        //bot
        //copnnect root to grandchild
        root->right = grandChild;
        grandChild->parent = root;
    }
}
//not possible to garantee equality
//close to equal, but sizes still bad

int main(){

    return 0;
}