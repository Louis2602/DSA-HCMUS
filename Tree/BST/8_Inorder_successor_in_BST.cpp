#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *createNode(int data)
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
Node *FindMin(Node *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}
Node *Find(Node *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (root->data == data)
        return root;
    else if (data <= root->data)
        return Find(root->left, data);
    else
        return Find(root->right, data);
}
// Function to find successor
Node *Getsuccessor(Node *root, int data)
{
    // Search the Node - O(h)
    Node *current = Find(root, data);
    if (current == NULL)
        return NULL;
    // Case 1: Node has right subtree
    if (current->right != NULL)
    {
        return FindMin(current->right); // O(h)
    }
    // Case 2: No right subtree - O(h)
    else
    {
        Node *successor = NULL;
        Node *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor; // so far this is the deepest node for which current node is in left
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}
int main()
{
    Node *root = NULL; // creating an empty tree
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 17);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 6);
    root = Insert(root, 11);
    root = Insert(root, 16);
    root = Insert(root, 27);

    int n;
    cout << "Enter your number: ";
    cin >> n;
    root = Getsuccessor(root, n);

    cout << "Successor: " << root->data;

    return 0;
}