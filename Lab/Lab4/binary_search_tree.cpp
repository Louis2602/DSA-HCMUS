#include <iostream>
#include <queue>
using namespace std;

struct NODE
{
    int data;
    NODE *left;
    NODE *right;
};

NODE *createNode(int data)
{
    NODE *p = new NODE;
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

void Insert(NODE *&pRoot, int x)
{
    if (pRoot == NULL)
    {
        pRoot = createNode(x);
        return;
    }
    if (x > pRoot->data)
        Insert(pRoot->right, x);
    else
        Insert(pRoot->left, x);
}

int countNode(NODE *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return 1 + countNode(pRoot->left) + countNode(pRoot->right);
}
int sumNode(NODE *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return (pRoot->data + sumNode(pRoot->left) + sumNode(pRoot->right));
}

NODE *Search(NODE *pRoot, int x)
{
    if (pRoot == NULL)
        return pRoot;
    if (x > pRoot->data)
        Search(pRoot->right, x);
    else if (x < pRoot->data)
        Search(pRoot->left, x);
    else
        return pRoot;
}

NODE *createTree(int a[], int n, int i)
{
    NODE *pRoot = NULL;
    if (i < n)
    {
        pRoot = createNode(a[i]);
        pRoot->left = createTree(a, n, 2 * i + 1);
        pRoot->right = createTree(a, n, 2 * i + 2);
    }
    return pRoot;
}

int Height(NODE *pRoot)
{
    if (pRoot == NULL)
        return 0;
    int left_height = Height(pRoot->left);
    int right_height = Height(pRoot->right);
    return max(left_height, right_height) + 1;
}

int getLength(NODE *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return 1 + getLength(pRoot->left) + getLength(pRoot->right);
}
bool isPerfectBST(NODE *pRoot)
{
    int len = getLength(pRoot);
    cout << len << endl;
    return !(len & (len + 1));
}
void preOrder(NODE *pRoot)
{
    if (pRoot == NULL)
        return;
    /* first print data of node */
    cout << pRoot->data << " ";
    /* then recur on left subtree */
    preOrder(pRoot->left);
    /* now recur on right subtree */
    preOrder(pRoot->right);
}
void inOrder(NODE *pRoot)
{
    if (pRoot == NULL)
        return;
    inOrder(pRoot->left);
    cout << pRoot->data << " ";
    inOrder(pRoot->right);
}
void postOrder(NODE *pRoot)
{
    if (pRoot == NULL)
        return;
    postOrder(pRoot->left);
    postOrder(pRoot->right);
    cout << pRoot->data << " ";
}
void LevelOrder(NODE *pRoot)
{
    if (pRoot == NULL)
        return;
    queue<NODE *> Q;
    Q.push(pRoot);
    while (!Q.empty())
    {
        NODE *cur = Q.front();
        cout << cur->data << " ";
        if (cur->left != NULL)
            Q.push(cur->left);
        if (cur->right != NULL)
            Q.push(cur->right);
        Q.pop();
    }
}
NODE *findMin(NODE *pRoot)
{
    NODE *cur = pRoot;
    while (cur && cur->left != NULL)
        cur = cur->left;
    return cur;
}
void Remove(NODE *&pRoot, int x)
{
    if (pRoot == NULL)
        return;
    if (x > pRoot->data)
        Remove(pRoot->right, x);
    else if (x < pRoot->data)
        Remove(pRoot->left, x);
    else
    {
        if (pRoot->left == NULL && pRoot->right == NULL)
        {
            delete pRoot;
            pRoot = NULL;
            return;
        }
        else if (pRoot->left == NULL)
        {
            NODE *t = pRoot;
            pRoot = pRoot->right;
            delete t;
        }
        else if (pRoot->right == NULL)
        {
            NODE *t = pRoot;
            pRoot = pRoot->left;
            delete t;
        }
        else
        {
            NODE *t = findMin(pRoot->right);
            pRoot->data = t->data;
            Remove(pRoot->right, t->data);
        }
    }
}
int countLeaf(NODE *pRoot)
{
    if (pRoot == NULL)
        return 0;
    if (pRoot->left == NULL && pRoot->right == NULL)
        return 1;
    return countLeaf(pRoot->left) + countLeaf(pRoot->right);
}
int countLess(NODE *pRoot, int x)
{
    int cnt = 0;
    if (pRoot == NULL)
        return 0;
    if (pRoot->data < x)
    {
        cnt++;
        cnt += countLess(pRoot->left, x);
        cnt += countLess(pRoot->right, x);
    }
    else
        cnt += countLess(pRoot->left, x);
    return cnt;
}
int countGreater(NODE *pRoot, int x)
{
    int cnt = 0;
    if (pRoot == NULL)
        return 0;
    if (pRoot->data > x)
    {
        cnt++;
        cnt += countGreater(pRoot->left, x);
        cnt += countGreater(pRoot->right, x);
    }
    else
        cnt += countGreater(pRoot->right, x);
    return cnt;
}
int main()
{
    NODE *pRoot = NULL;
    // int a[] = {5, 3, 6, 4, 2, 7};
    Insert(pRoot, 5);
    Insert(pRoot, 3);
    Insert(pRoot, 7);
    Insert(pRoot, 6);
    Insert(pRoot, 4);
    Insert(pRoot, 2);
    // Insert(pRoot, 8);
    cout << "LevelOrder: ";
    LevelOrder(pRoot); // 5 3 6 4 2 7
    cout << '\n';
    /*cout << "\nNumber of nodes: " << countNode(pRoot) << '\n';
    cout << "Sum of all nodes: " << sumNode(pRoot) << '\n';
    NODE *search = Search(pRoot, 6);
    if(search != NULL)
        cout << "Found!";
    else
        cout << "Not found!";*/
    /*int n = sizeof(a) / sizeof(a[0]);
    NODE *r = createTree(a, n, 0);*/
    cout << "PreOrder: ";
    preOrder(pRoot); // 5 3 2 4 6 7
    cout << '\n';
    cout << "InOrder: ";
    inOrder(pRoot); // 2 3 4 5 6 7
    cout << '\n';
    cout << "PostOrder: ";
    postOrder(pRoot); // 2 4 3 7 6 5
    cout << '\n';
    cout << "Height = ";
    cout << Height(pRoot);
    cout << '\n';
    /*if(isPerfectBST(pRoot))
        cout << "YES\n";
    else cout << "NO\n";*/
    cout << "Remove = ";
    Remove(pRoot, 7);
    LevelOrder(pRoot); // 5 3 6 4 2 7
    cout << '\n';
    cout << "Leaf Nodes = " << countLeaf(pRoot);
    cout << '\n';
    int x;
    cin >> x;
    cout << "Nodes less than " << x << " = " << countLess(pRoot, x);
    cout << '\n';
    cout << "Nodes greater than " << x << " = " << countGreater(pRoot, x);
    cout << '\n';
    return 0;
}