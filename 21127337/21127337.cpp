#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <sstream>

using namespace std;

struct Company
{
    string name;
    string mst;
    string addr;
};

struct Node
{
    Company cp;
    Node *left;
    Node *right;
};

Node *createNode(Company c)
{
    Node *p = new Node;
    p->cp = c;
    p->left = p->right = NULL;
    return p;
}
void Insert(Node *&pRoot, Company c)
{
    if (pRoot == NULL)
    {
        pRoot = createNode(c);
        return;
    }
    if (c.mst > (pRoot->cp).mst)
        Insert(pRoot->right, c);
    else if (c.mst < (pRoot->cp).mst)
        Insert(pRoot->left, c);
    else
        return;
}
void createTree(Node *&pRoot)
{
    fstream fs("MST.txt", ios::in);
    string s;
    getline(fs, s);
    Company c;
    while (!fs.eof())
    {
        getline(fs, c.name, '|');
        getline(fs, c.mst, '|');
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
        cout << (cur->cp).name << endl;
        Q.pop();
        if (cur->left)
            Q.push(cur->left);
        if (cur->right)
            Q.push(cur->right);
    }
}

Node *findMin(Node *pRoot)
{
    Node *cur = pRoot;
    while (cur && cur->left)
        cur = cur->left;
    return cur;
}
void deleteNode(Node *&pRoot, string MST)
{
    if (pRoot == NULL)
        return;
    if (MST > pRoot->cp.mst)
        deleteNode(pRoot->right, MST);
    else if (MST < pRoot->cp.mst)
        deleteNode(pRoot->left, MST);
    else
    {
        if (pRoot->left == NULL && pRoot->right == NULL)
        {
            delete pRoot;
            pRoot = NULL;
            return;
        }
        else if (pRoot->left == NULL)
        {
            Node *q = pRoot;
            pRoot = pRoot->right;
            delete q;
        }
        else if (pRoot->right == NULL)
        {
            Node *q = pRoot;
            pRoot = pRoot->left;
            delete q;
        }
        else
        {
            Node *q = findMin(pRoot->right);
            pRoot->cp = q->cp;
            deleteNode(pRoot->right, q->cp.mst);
        }
    }
}
void removeCompany(Node *&pRoot, int x)
{
    if (pRoot == NULL)
        return;
    removeCompany(pRoot->left, x);
    removeCompany(pRoot->right, x);
    stringstream ss((pRoot->cp).mst);
    long long t;
    ss >> t;
    t %= 100;
    if (x == t)
        deleteNode(pRoot, (pRoot->cp).mst);
}

int main()
{
    Node *pRoot = NULL;
    createTree(pRoot);
    levelOrder(pRoot);
    removeCompany(pRoot, 62);
    levelOrder(pRoot);
    return 0;
}
