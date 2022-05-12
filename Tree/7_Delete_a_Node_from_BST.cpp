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
    {
        return root;
    }
    else if (root->left == NULL)
        return root;
    return FindMin(root->left);
}
Node *Delete(Node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else // found the node and get ready to be deleted
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // Case 2: 1 child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: 2 children
        else
        {
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}
void LevelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> Q;
    Q.push(root);
    // while there is at least one discovered node
    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop(); // removing element at front
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
    root = Insert(root, 13);
    root = Insert(root, 9);
    root = Insert(root, 27);

    int number;
    cout << "Enter a number you want to be deleted from BST: ";
    cin >> number;
    Delete(root, number);
    LevelOrder(root);
    return 0;
}