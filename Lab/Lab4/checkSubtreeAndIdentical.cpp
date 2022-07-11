#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node *left;
	Node *right;
};

Node *createNode(int x)
{
	Node *p = new Node;
	p->key = x;
	p->left = p->right = NULL;
	return p;
}

void Insert(Node *&root, int x)
{
	if (root == NULL)
	{
		root = createNode(x);
		return;
	}
	if (x > root->key)
	{
		Insert(root->right, x);
	}
	else if (x < root->key)
	{
		Insert(root->left, x);
	}
	else
		return;
}
bool areIdentical(Node *root1, Node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;

	if (root1 == NULL || root2 == NULL)
		return false;
	return (root1->key == root2->key &&
			areIdentical(root1->left, root2->left) &&
			areIdentical(root1->right, root2->right));
}
bool isMirror(Node *root1, Node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;
	if (root1 == NULL || root2 == NULL)
		return false;
	return (root1->key == root2->key &&
			areIdentical(root1->left, root2->right) &&
			areIdentical(root1->right, root2->left));
}
bool isSubtree(Node *T, Node *S)
{
	if (S == NULL)
		return true;
	if (T == NULL)
		return false;
	if (areIdentical(T, S))
		return true;
	return isSubtree(T->left, S) ||
		   isSubtree(T->right, S);
}

int main()
{
	return 0;
}
