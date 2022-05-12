#include <bits/stdc++.h>
#include <queue>
/*Breadth First Traversal */
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
        return GetNewNode(data);
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
void LevelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> Q;
    Q.push(root);
    //while there is at least one discovered node
    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop(); //removing element at front
    }
}
int main()
{
    Node *root = NULL; // creating an empty tree
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 17);
    root = Insert(root, 12);
    LevelOrder(root);
    return 0;
}