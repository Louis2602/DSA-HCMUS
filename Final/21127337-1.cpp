#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
struct Node
{
    int x;
    int y;
    Node *left;
    Node *right;
};
Node *createNode(int x, int y)
{
    Node *p = new Node;
    p->x = x;
    p->y = y;
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
    if (h > 1)
    {
        if (height(pRoot->left->left) >= height(pRoot->left->right))
            rightRotate(pRoot);
        else
        {
            leftRotate(pRoot->left);
            rightRotate(pRoot);
        }
    }
    if (h < -1)
    {
        if (height(pRoot->right->right) >= height(pRoot->right->left))
            leftRotate(pRoot);
        else
        {
            rightRotate(pRoot->right);
            leftRotate(pRoot);
        }
    }
}
void Insert(Node *&pRoot, int x, int y)
{
    if (pRoot == NULL)
    {
        pRoot = createNode(x, y);
        return;
    }
    if ((pRoot->x * pRoot->y > x * y) || (x * y == pRoot->x * pRoot->y && x < pRoot->x))
        Insert(pRoot->left, x, y);
    else
        Insert(pRoot->right, x, y);
    balance(pRoot);
}
Node *findMin(Node *pRoot)
{
    while (pRoot->left)
        pRoot = pRoot->left;
    return pRoot;
}
void remove(Node *&pRoot, int x, int y)
{
    if (pRoot == NULL)
        return;
    if ((pRoot->x * pRoot->y > x * y) || (x * y == pRoot->x * pRoot->y && x < pRoot->x))
        remove(pRoot->left, x, y);
    else
        remove(pRoot->right, x, y);
    if (pRoot->x == x && pRoot->y == y)
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
            pRoot->x = t->x;
            pRoot->y = t->y;
            remove(pRoot->right, t->x, t->y);
        }
    }
    if (pRoot != NULL)
        balance(pRoot);
}
Node *createTree()
{
    fstream fs("inputAVLCLC8.txt", ios::in);
    Node *pRoot = NULL;
    int x, y;
    while (!fs.eof())
    {
        fs >> x >> y;
        Insert(pRoot, x, y);
    }
    fs.close();
    return pRoot;
}

void levelOrder(Node *pRoot)
{
    queue<Node *> Q;
    Q.push(pRoot);
    while (!Q.empty())
    {
        Node *cur = Q.front();
        cout << "(" << cur->x << ", " << cur->y << ")"
             << " - ";
        Q.pop();
        if (cur->left)
            Q.push(cur->left);
        if (cur->right)
            Q.push(cur->right);
    }
    cout << '\n';
}

int main()
{
    Node *r = createTree();
    levelOrder(r);
    remove(r, 168, 2625);
    levelOrder(r);
    return 0;
}