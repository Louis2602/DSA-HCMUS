#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

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
Node *Insert(vector<int> a, int n, int i)
{
    Node *pRoot = NULL;
    if (i < n)
    {
        pRoot = createNode(a[i]);
        pRoot->left = Insert(a, n, 2 * i + 1);
        pRoot->right = Insert(a, n, 2 * i + 2);
    }
    return pRoot;
}
Node *buildTree(vector<int> a)
{
    fstream fs("inputBinaryTreeCLC8 (1).txt", ios::in);
    int n;
    string s;
    while (!fs.eof())
    {
        fs >> n;
        a.push_back(n);
    }
    Node *tree = Insert(a, a.size(), 0);
    fs.close();
    return tree;
}
int countNodes(Node *pRoot)
{
    if (pRoot == NULL || pRoot->key == -1)
        return 0;
    return 1 + countNodes(pRoot->left) + countNodes(pRoot->right);
}

bool check(Node *pRoot, int index, int numNodes)
{
    if (pRoot == NULL || pRoot->key == -1)
        return 1;
    if (index >= numNodes)
        return 0;
    return check(pRoot->left, 2 * index + 1, numNodes) && check(pRoot->right, 2 * index + 2, numNodes);
}

bool isComplete(Node *pRoot)
{
    int n = countNodes(pRoot);
    if (check(pRoot, 0, n))
        return 1;
    return 0;
}
void levelOrder(Node *pRoot)
{
    queue<Node *> Q;
    Q.push(pRoot);
    while (!Q.empty())
    {
        Node *cur = Q.front();
        if (cur->key != -1)
            cout << cur->key << " ";
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
    vector<int> a;
    Node *r = buildTree(a);
    levelOrder(r);
    cout << isComplete(r);
    return 0;
}