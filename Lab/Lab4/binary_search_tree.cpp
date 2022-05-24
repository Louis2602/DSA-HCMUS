#include <iostream>
using namespace std;

struct NODE {
    int data;
    NODE *left;
    NODE *right;
};

NODE *createNode(int data) {
    NODE *p = new NODE;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void Insert(NODE *&pRoot, int x) {
    if(pRoot == NULL) {
        pRoot = createNode(x);
        return;
    }
    if(x > pRoot->data) {
        Insert(pRoot->right, x);
    } else {
        Insert(pRoot->left, x);
    }
}
void printPreorder(NODE* pRoot)
{
    if (pRoot == NULL)
        return;
    /* first print data of node */
    cout << pRoot->data << " ";
    /* then recur on left subtree */
    printPreorder(pRoot->left);
    /* now recur on right subtree */
    printPreorder(pRoot->right);
}
int main() {
    NODE *pRoot = NULL;
    Insert(pRoot, 5);
    Insert(pRoot, 7);
    Insert(pRoot, 9);
    Insert(pRoot, 1);
    Insert(pRoot, 10);
    Insert(pRoot, 11);
    Insert(pRoot, 15);
    printPreorder(pRoot);
    return 0;
}
