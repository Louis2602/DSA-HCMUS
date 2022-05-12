#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};
Node *createNode(char data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node *Insert(Node *root, char data)
{
    if (root == NULL) // empty tree
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}
void PreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(Node *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(Node *root)
{
    if (root == NULL)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL; // creating an empty tree
    root = Insert(root, 'F');
    root = Insert(root, 'D');
    root = Insert(root, 'J');
    root = Insert(root, 'B');
    root = Insert(root, 'E');
    root = Insert(root, 'G');
    root = Insert(root, 'K');
    root = Insert(root, 'A');
    root = Insert(root, 'C');
    root = Insert(root, 'I');
    root = Insert(root, 'H');
    // cout << root->data << " ";
    cout << "Pre-order Tree: ";
    PreOrder(root);
    cout << "\nIn-order Tree: ";
    InOrder(root);
    cout << "\nPost-order Tree: ";
    PostOrder(root);
    return 0;
}