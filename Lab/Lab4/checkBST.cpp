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

// int minVal(Node *pRoot)
// {
//     if (pRoot == NULL)
//         return 10000000;
//     if (pRoot->left == NULL && pRoot->right == NULL)
//         return pRoot->key;
//     return min(minVal(pRoot->left), minVal(pRoot->right));
// }
// int maxVal(Node *pRoot)
// {
//     if (pRoot == NULL)
//         return -10000000;
//     if (pRoot->left == NULL && pRoot->right == NULL)
//         return pRoot->key;
//     return max(maxVal(pRoot->left), maxVal(pRoot->right));
// }
// bool isBST(Node *pRoot)
// {
//     if (pRoot == NULL)
//         return 1;
//     if (pRoot->key < maxVal(pRoot->left) || pRoot->key > minVal(pRoot->right))
//         return 0;
//     return isBST(pRoot->left) && isBST(pRoot->right);
// }

bool isSubtreeLesser(Node *root, int value)
{
    if (root == NULL)
        return true;
    if (root->key <= value && isSubtreeLesser(root->left, value) && isSubtreeLesser(root->right, value))
        return true;
    else
        return false;
}
bool isSubtreeGreater(Node *root, int value)
{

    if (root == NULL)
        return true;
    if (root->key > value && isSubtreeGreater(root->left, value) && isSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}
// Cach 1
bool isBST(Node *root)
{
    if (root == NULL)
        return true;
    if (isSubtreeLesser(root->left, root->key) && isSubtreeGreater(root->right, root->key) && isBST(root->left) && isBST(root->right))
        return true;
    else
        return false;
}
// Cach 2
bool isBstUtil(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;
    if (root->key > minValue && root->key < maxValue && isBstUtil(root->left, minValue, root->key) && isBstUtil(root->right, root->key, maxValue))
        return true;
    else
        return false;
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
    Node *root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(4);
    // root->right->right = createNode(8);
    // root->right->left = createNode(6)

    if (isBstUtil(root, -1000, 1000))
        cout << "Is BST\n";
    else
        cout << "Not BST\n";

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
