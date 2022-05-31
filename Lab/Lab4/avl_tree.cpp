#include <iostream>
#include <queue>
using namespace std;
struct NODE
{
	int key;
	NODE *left;
	NODE *right;
	int height;
};

int height(NODE *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
NODE *createNode(int key)
{
	NODE *node = new NODE;
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

NODE *rightRotate(NODE *y)
{
	NODE *x = y->left;
	NODE *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
					height(y->right)) +
				1;
	x->height = max(height(x->left),
					height(x->right)) +
				1;
	// Return new root
	return x;
}
NODE *leftRotate(NODE *x)
{
	NODE *y = x->right;
	NODE *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) +
				1;
	y->height = max(height(y->left),
					height(y->right)) +
				1;
	// Return new root
	return y;
}

int getBalance(NODE *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

NODE *Insert(NODE *pRoot, int key)
{
	if (pRoot == NULL)
		return (createNode(key));

	if (key < pRoot->key)
		pRoot->left = Insert(pRoot->left, key);
	else if (key > pRoot->key)
		pRoot->right = Insert(pRoot->right, key);
	else // Equal keys are not allowed in BST
		return pRoot;

	/* 2. Update height of this ancestor node */
	pRoot->height = 1 + max(height(pRoot->left),
							height(pRoot->right));

	int balance = getBalance(pRoot);

	// Left Left Case
	if (balance > 1 && key < pRoot->left->key)
		return rightRotate(pRoot);

	// Right Right Case
	if (balance < -1 && key > pRoot->right->key)
		return leftRotate(pRoot);

	// Left Right Case
	if (balance > 1 && key > pRoot->left->key)
	{
		pRoot->left = leftRotate(pRoot->left);
		return rightRotate(pRoot);
	}

	// Right Left Case
	if (balance < -1 && key < pRoot->right->key)
	{
		pRoot->right = rightRotate(pRoot->right);
		return leftRotate(pRoot);
	}

	return pRoot;
}

void preOrder(NODE *pRoot)
{
	if (pRoot != NULL)
	{
		cout << pRoot->key << " ";
		preOrder(pRoot->left);
		preOrder(pRoot->right);
	}
}

void levelOrder(NODE *pRoot)
{
	if (pRoot == NULL)
		return;
	queue<NODE *> Q;
	Q.push(pRoot);
	while (!Q.empty())
	{
		NODE *cur = Q.front();
		cout << cur->key << " ";
		if (cur->left != NULL)
			Q.push(cur->left);
		if (cur->right != NULL)
			Q.push(cur->right);
		Q.pop();
	}
}
int main()
{
	NODE *pRoot = NULL;
	pRoot = Insert(pRoot, 10);
	pRoot = Insert(pRoot, 20);
	pRoot = Insert(pRoot, 30);
	pRoot = Insert(pRoot, 40);
	pRoot = Insert(pRoot, 50);
	pRoot = Insert(pRoot, 25);
	pRoot = Insert(pRoot, 35);

	/* The constructed AVL Tree would be
				30
			   / \
			  20 40
			 / \   \
			10 25  50
	*/
	cout << "Preorder traversal of the "
			"constructed AVL tree is \n";
	// preOrder(pRoot);
	levelOrder(pRoot);

	return 0;
}
