#include <iostream>
#include <queue>
using namespace std;

struct NODE {
    int data;
    NODE *left;
    NODE *right;
};

NODE *createNode(int data) {
    NODE *p = new NODE;
    p->data = data;
    p->left = p->right = NULL;
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
void LevelOrder(NODE* pRoot) {
    if (pRoot == NULL)
        return;
    queue<NODE *> Q;
    Q.push(pRoot);
    while(!Q.empty()) {
        NODE *cur = Q.front();
        cout << cur->data << " ";
        if(cur->left != NULL)
            Q.push(cur->left);
        if(cur->right != NULL)
            Q.push(cur->right);
        Q.pop();
    }
    cout << '\n';
}

int countNode(NODE* pRoot) {
    if(pRoot == NULL)
        return 0;
    return 1 + countNode(pRoot->left) + countNode(pRoot->right);
}
int sumNode(NODE* pRoot) {
    if(pRoot == NULL)
        return 0;
    return (pRoot->data + sumNode(pRoot->left) + sumNode(pRoot->right));
}

NODE* Search(NODE* pRoot, int x) {
    if(pRoot == NULL)
        return pRoot;
    if(x > pRoot->data)
        Search(pRoot->right, x);
    else if(x < pRoot->data)
        Search(pRoot->left, x);
    else
        return pRoot;
}

NODE *createTree(int a[], int n, int i) {
    NODE *pRoot = NULL;
    if(i < n) {
        pRoot = createNode(a[i]);
        pRoot->left = createTree(a, n, 2*i+1);
        pRoot->right = createTree(a, n, 2*i+2);
    }
    return pRoot;
}

void inOrder(NODE *pRoot) {
    if(pRoot != NULL) {
        inOrder(pRoot->left);
        cout << pRoot->data << " ";
        inOrder(pRoot->right);
    }
}
int main() {
    NODE *pRoot = NULL;
    int a[] = {1, 2, 3, 4, 5, 6};
    Insert(pRoot, 1);
    Insert(pRoot, 2);
    Insert(pRoot, 3);
    Insert(pRoot, 4);
    Insert(pRoot, 5);
    Insert(pRoot, 6);
    //printPreorder(pRoot);
    LevelOrder(pRoot);
    /*cout << "\nNumber of nodes: " << countNode(pRoot) << '\n';
    cout << "Sum of all nodes: " << sumNode(pRoot) << '\n';
    NODE *search = Search(pRoot, 6);
    if(search != NULL)
        cout << "Found!";
    else
        cout << "Not found!";*/
    int n = sizeof(a) / sizeof(a[0]);
    NODE *r = createTree(a, n, 0);
    LevelOrder(r);
    return 0;
}
