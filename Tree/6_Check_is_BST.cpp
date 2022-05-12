#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *GetNewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node *Insert(Node *root, int data)
{
    if (root == NULL) // empty tree
    {
        root = GetNewNode(data);
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
bool isSubtreeLesser(Node *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data <= value && isSubtreeLesser(root->left, value) && isSubtreeLesser(root->right, value))
        return true;
    else
        return false;
}
bool isSubtreeGreater(Node *root, int value)
{

    if (root == NULL)
        return true;
    if (root->data > value && isSubtreeGreater(root->left, value) && isSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}
// Cach 1
bool isBinarySearchTree(Node *root)
{
    if (root == NULL)
        return true;
    if (isSubtreeLesser(root->left, root->data) && isSubtreeGreater(root->right, root->data) && isBinarySearchTree(root->left) && isBinarySearchTree(root->right))
        return true;
    else
        return false;
}
// Cach 2
bool isBstUtil(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;
    if (root->data > minValue && root->data < maxValue && isBstUtil(root->left, minValue, root->data) && isBstUtil(root->right, root->data, maxValue))
        return true;
    else
        return false;
}

int main()
{
    Node *root = NULL; // creating an empty tree
    root = Insert(root, 7);
    root = Insert(root, 4);
    root = Insert(root, 9);
    root = Insert(root, 1);
    root = Insert(root, 6);
    cout << "Cach 1: ";
    if (isBinarySearchTree(root) == 1)
        cout << "true";
    else
        cout << "false";
    cout << endl;
    cout << "Cach 2: ";
    if (isBstUtil(root, INT_MIN, INT_MAX) == 1)
        cout << "true";
    else
        cout << "false";
    return 0;
}