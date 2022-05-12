#include <bits/stdc++.h>
using namespace std;
struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};
BstNode *createNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BstNode *Insert(BstNode *root, int data)
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
bool Search(BstNode *root, int number)
{
    if (root == NULL)
        return false;
    else if (root->data == number)
        return true;
    else if (number <= root->data)
        return Search(root->left, number);
    else
        return Search(root->right, number);
}

int main()
{
    BstNode *root = NULL; // creating an empty tree
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    int number;
    cout << "Enter a number to be searched: ";
    cin >> number;
    if (Search(root, number) == true)
        cout << "Found!";
    else
        cout << "Not found!";
    return 0;
}