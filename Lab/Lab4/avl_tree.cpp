#include <iostream>
using namespace std;

struct NODE {
    int key;
    NODE *left;
    NODE *right;
    int height;
};

NODE *createNode(int data) {
    NODE *p = new NODE;
    p->key = data;
    p->left = p->right = NULL;
    p->height = 1;
    return p;
}

int height(NODE *N) {
    if(N == NULL)
        return 0;
    return N->height;
}
NODE *rightRotate(NODE *y) {
    NODE *x = y->left;
    NODE *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

NODE *leftRotate(NODE *x) {
    NODE *y = x->left;
    NODE *T2 = x->right;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update height
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(NODE *N) {
    if(N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
void Insert(NODE *&pRoot, int x) {
    if(pRoot == NULL) {
        pRoot = createNode(x);
        return;
    }

    if(x < pRoot->key)
        Insert(pRoot->left, x);
    else if(x > pRoot->key)
        Insert(pRoot->right, x);

    pRoot->height = 1 + max(height(pRoot->left), height(pRoot->right));

    int balance = getBalance(pRoot);

    // Left left case
    if(balance > 1 && x < pRoot->left->key)
        rightRotate(pRoot);
    // Right right case
    if(balance < -1 && x > pRoot->right->key)
        leftRotate(pRoot);
    // Left right case
    if(balance > 1 && x > pRoot->left->key) {
        pRoot->left = leftRotate(pRoot->left);
        rightRotate(pRoot);
    }
    // Right left case
    if(balance < -1 && x < pRoot->right->key) {
        pRoot->right = rightRotate(pRoot->right);
        leftRotate(pRoot);
    }
}

void preOrder(NODE *pRoot) {
    if(pRoot != NULL) {
        cout << pRoot->key << " ";
        preOrder(pRoot->left);
        preOrder(pRoot->right);
    }
}

int main() {
    NODE *pRoot = NULL;
    Insert(pRoot, 10);
    Insert(pRoot, 20);
    Insert(pRoot, 30);
    Insert(pRoot, 40);
    Insert(pRoot, 50);
    Insert(pRoot, 25);
    cout << "AVL Tree: ";
    preOrder(pRoot);

    return 0;
}
