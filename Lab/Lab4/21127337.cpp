#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

struct Company
{
    string name;
    string tax;
    string addr;
};

struct Node
{
    Company c;
    Node *left;
    Node *right;
};

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
Node *createNode(Company cp)
{
    Node *p = new Node;
    p->c = cp;
    p->left = p->right = NULL;
    return p;
}
int Height(Node *pRoot)
{
    if (pRoot == NULL)
        return 0;
    int lh = Height(pRoot->left);
    int rh = Height(pRoot->right);
    return 1 + max(lh, rh);
}
void balance(Node *&pRoot)
{
    int bal = Height(pRoot->left) - Height(pRoot->right);
    if (bal >= 2)
    {
        if (Height(pRoot->left->left) >= Height(pRoot->left->right))
            rightRotate(pRoot->left);
        else
        {
            leftRotate(pRoot->left);
            rightRotate(pRoot);
        }
    }
    if (bal <= -2)
    {
        if (Height(pRoot->right->right) >= Height(pRoot->right->left))
            leftRotate(pRoot->right);
        else
        {
            rightRotate(pRoot->right);
            leftRotate(pRoot);
        }
    }
}
void Insert(Node *&pRoot, Company c)
{
    if (pRoot == NULL)
    {
        pRoot = createNode(c);
        return;
    }
    if (c.tax > pRoot->c.tax)
        Insert(pRoot->right, c);
    else if (c.tax < pRoot->c.tax)
        Insert(pRoot->left, c);
    balance(pRoot);
}
void createTree(Node *&pRoot)
{
    fstream fs("MST.txt", ios::in);
    string s;
    fs >> s;
    Company c;
    while (!fs.eof())
    {
        getline(fs, c.name, '|');
        getline(fs, c.tax, '|');
        getline(fs, c.addr);
        Insert(pRoot, c);
    }
    fs.close();
}
void levelOrder(Node *pRoot)
{
    queue<Node *> Q;
    Q.push(pRoot);
    while (!Q.empty())
    {
        Node *cur = Q.front();
        cout << cur->c.name << endl;
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
    createTree(pRoot);
    levelOrder(pRoot);
    return 0;
}