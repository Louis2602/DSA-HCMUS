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

int FindHeight(BstNode *root)
{
    if (root == NULL)
        return -1;
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

int main()
{
    BstNode *root = NULL; // creating an empty tree
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 17);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 9);
    root = Insert(root, 13);

    cout << "The height of BST: " << FindHeight(root) << endl;
    return 0;
}