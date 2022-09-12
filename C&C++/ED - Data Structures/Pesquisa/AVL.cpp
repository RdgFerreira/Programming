#include <iostream>
using namespace std;

typedef struct node {
    int value;
    int height;
    struct node *leftChild;
    struct node *rightChild;
    struct node *parent;
} node_t;

int max(int v1, int v2) {
    if (v1 > v2) return v1;
    else return v2;
}

int height(node_t *node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->leftChild), height(node->rightChild)); 
}

int balanceFactor(node_t *node) {
    if (node == NULL) return 0;

    // int balance = height(node->rightChild) - height(node->leftChild);
    int balance = node->rightChild->height - node->leftChild->height;
    return balance;
}


int main() {



    return 0;
}