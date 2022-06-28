#include <iostream>
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

int minVal(Node *pRoot)
{
    if (pRoot == NULL)
        return 10000000;
    if (pRoot->left == NULL && pRoot->right == NULL)
        return pRoot->key;
    return min(minVal(pRoot->left), minVal(pRoot->right));
}
int maxVal(Node *pRoot)
{
    if (pRoot == NULL)
        return -10000000;
    if (pRoot->left == NULL && pRoot->right == NULL)
        return pRoot->key;
    return max(maxVal(pRoot->left), maxVal(pRoot->right));
}
bool isBST(Node *pRoot)
{
    if (pRoot == NULL)
        return 1;
    if (pRoot->key < maxVal(pRoot->left) || pRoot->key > minVal(pRoot->right))
        return 0;
    return isBST(pRoot->left) && isBST(pRoot->right);
}
bool isFullBst(Node *pRoot)
{
    if (isBST(pRoot))
    {
        if (pRoot == NULL)
            return 1;
        if (pRoot->left == NULL && pRoot->right == NULL)
            return true;
        if (pRoot->left && pRoot->right)
            return isFullBst(pRoot->left) && isFullBst(pRoot->right);
    }
    return 0;
}
int countNode(Node *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return 1 + countNode(pRoot->left) + countNode(pRoot->right);
}
bool isPerfectBST(Node *pRoot)
{
    int len = countNode(pRoot);
    cout << len << endl;
    return !(len & (len + 1));
}
bool isCompleteBST(Node *pRoot, int index, int numNodes)
{
    if (pRoot == NULL)
        return 1;
    if (index >= numNodes)
        return 0;
    return isCompleteBST(pRoot->left, 2 * index + 1, numNodes) && isCompleteBST(pRoot->right, 2 * index + 2, numNodes);
}
int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    // root->right->left = createNode(6);
    root->right->right = createNode(9);

    // if (isBST(root))
    //     cout << "Is BST\n";
    // else
    //     cout << "Not BST\n";

    // if (isFullBst(root))
    //     cout << "Is Full BST\n";
    // else
    //     cout << "Not Full BST\n";

    // if (isPerfectBST(root))
    //     cout << "Is Perfect BST\n";
    // else
    //     cout << "Not Perfect BST\n";
    int numNodes = countNode(root);
    if (isCompleteBST(root, 0, numNodes))
        cout << "Is Complete BST\n";
    else
        cout << "Not Complete BST\n";
    return 0;
}