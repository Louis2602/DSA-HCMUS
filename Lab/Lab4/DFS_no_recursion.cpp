#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
};
Node *createNode(int data)
{
    Node *p = new Node;
    p->key = data;
    p->left = p->right = NULL;
    return p;
}
void inOrder(Node *pRoot)
{
    if (pRoot == NULL)
        return;
    stack<Node *> s;
    Node *curr = pRoot;
    while (curr || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }
}

void preOrder(Node *pRoot)
{
    if (pRoot == NULL)
        return;
    stack<Node *> s;
    Node *curr = pRoot;
    s.push(curr);
    while (!s.empty())
    {
        curr = s.top();
        cout << curr->key << " ";
        s.pop();
        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
}
void postOrder(Node *pRoot)
{
    if (pRoot == NULL)
        return;
    stack<Node *> s;
    s.push(pRoot);
    stack<int> out;
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        out.push(curr->key);
        if (curr->left)
            s.push(curr->left);
        if (curr->right)
            s.push(curr->right);
    }
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}
int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    cout << "Inorder: ";
    inOrder(root);
    cout << "\nPreorder: ";
    preOrder(root);
    cout << "\nPostorder: ";
    postOrder(root);
    return 0;
}