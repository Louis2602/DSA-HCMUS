#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
};
Node *createNode(int x)
{
    Node *p = new Node;
    p->key = x;
    p->left = p->right = NULL;
    return p;
}
void leftRotate(Node *&pRoot)
{
    Node *p = pRoot->right;
    pRoot->right = p->left;
    p->left = pRoot;
    pRoot = p;
}
void rightRotate(Node *&pRoot)
{
    Node *p = pRoot->left;
    pRoot->left = p->right;
    p->right = pRoot;
    pRoot = p;
}
int height(Node *pRoot)
{
    if (pRoot == NULL)
        return 0;
    int lh = height(pRoot->left);
    int rh = height(pRoot->right);
    return 1 + max(lh, rh);
}
void balance(Node *&pRoot)
{
    int h = height(pRoot->left) - height(pRoot->right);
    // MCB trai
    if (h >= 2)
    {
        if (height(pRoot->left->left) >= height(pRoot->left->right))
            rightRotate(pRoot);
        if (height(pRoot->left->left) < height(pRoot->left->right))
        {
            leftRotate(pRoot->left);
            rightRotate(pRoot);
        }
    }
    // MCB phai
    if (h <= -2)
    {
        if (height(pRoot->right->right) >= height(pRoot->right->left))
            leftRotate(pRoot);
        if (height(pRoot->right->right) < height(pRoot->right->left))
        {
            rightRotate(pRoot->right);
            leftRotate(pRoot);
        }
    }
}
void Insert(Node *&pRoot, int x)
{
    if (pRoot == NULL)
    {
        pRoot = createNode(x);
        return;
    }
    if (x > pRoot->key)
        Insert(pRoot->right, x);
    if (x < pRoot->key)
        Insert(pRoot->left, x);
    balance(pRoot);
}
Node *findMin(Node *pRoot)
{
    while (pRoot->left)
        pRoot = pRoot->left;
    return pRoot;
}
void Remove(Node *&pRoot, int x)
{
    if (pRoot == NULL)
        return;
    if (x > pRoot->key)
        Remove(pRoot->right, x);
    else if (x < pRoot->key)
        Remove(pRoot->left, x);
    else
    {
        if (pRoot->left == NULL && pRoot->right == NULL)
        {
            delete pRoot;
            pRoot = NULL;
        }
        else if (pRoot->left == NULL)
        {
            Node *t = pRoot;
            pRoot = pRoot->right;
            delete t;
        }
        else if (pRoot->right == NULL)
        {
            Node *t = pRoot;
            pRoot = pRoot->left;
            delete t;
        }
        else
        {
            Node *t = findMin(pRoot->right);
            pRoot->key = t->key;
            Remove(pRoot->right, t->key);
        }
    }
    if (pRoot != NULL)
        balance(pRoot);
}
void levelOrder(Node *pRoot)
{
    queue<Node *> Q;
    Q.push(pRoot);
    while (!Q.empty())
    {
        Node *cur = Q.front();
        cout << cur->key << " ";
        Q.pop();
        if (cur->left)
            Q.push(cur->left);
        if (cur->right)
            Q.push(cur->right);
    }
}

int main()
{
    Node *pRoot = NULL;
    Insert(pRoot, 12);
    Insert(pRoot, 8);
    Insert(pRoot, 18);
    Insert(pRoot, 5);
    Insert(pRoot, 11);
    Insert(pRoot, 17);
    Insert(pRoot, 4);
    Insert(pRoot, 7);
    Insert(pRoot, 2);
    levelOrder(pRoot);
    cout << '\n';
    Remove(pRoot, 17);
    levelOrder(pRoot);
    return 0;
}