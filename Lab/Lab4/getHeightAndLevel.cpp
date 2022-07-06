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
    else if (x < pRoot->data)
        Insert(pRoot->left, x);
    else
        return;
}

int Height(NODE *pRoot, int x, int &height)
{
    if (pRoot == NULL)
        return 0;
    int left_height = Height(pRoot->left, x, height);
    int right_height = Height(pRoot->right, x, height);
    int ans = max(left_height, right_height) + 1;
    if (pRoot->data == x)
        height = ans;
    return ans;
}
int heightOfNode(NODE *pRoot, int value)
{
    int h = -1;
    int maxHeight = Height(pRoot, value, h);
    return h;
}
int levelOfNode(NODE *pRoot, int value)
{
    queue<NODE *> q;
    int level = 1;
    q.push(pRoot);
    q.push(NULL);
    while (!q.empty())
    {
        NODE *t = q.front();
        q.pop();
        if (t == NULL)
        {
            if (q.front() != NULL)
                q.push(NULL);
            level++;
        }
        else
        {
            if (t->data == value)
                return level;
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
    }
    return 0;
}

int find(NODE *pRoot, NODE *p, int level)
{
    if (pRoot == NULL)
        return 0;
    if (pRoot->data == p->data)
        return level;
    int x = find(pRoot->left, p, level + 1);
    if (x != 0)
        return x;
    x = find(pRoot->right, p, level + 1);
    return x;
}

int LevelOfNode_2(NODE *pRoot, NODE *p)
{
    if (pRoot == NULL)
        return 0;
    int level = 1;
    return find(pRoot, p, level);
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
    cout << '\n';
}
int main()
{
    NODE *pRoot = NULL;
    Insert(pRoot, 5);
    Insert(pRoot, 3);
    Insert(pRoot, 7);
    Insert(pRoot, 6);
    Insert(pRoot, 4);
    Insert(pRoot, 2);
    Insert(pRoot, 1);
    Insert(pRoot, 0);
    cout << "BST: ";
    LevelOrder(pRoot);
    int value;
    cout << "Enter a value to find the height and level of its node in BST: ";
    cin >> value;
    cout << "Height of " << value << " is: " << heightOfNode(pRoot, value) << '\n';
    NODE *p = createNode(4);
    cout << "Level of " << value << " is: " << levelOfNode(pRoot, value) << '\n';
    cout << "Level of " << value << " is: " << LevelOfNode_2(pRoot, p) << '\n';
    return 0;
}
