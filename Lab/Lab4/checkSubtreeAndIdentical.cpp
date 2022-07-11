#include <iostream>
using namespace std;

struct Node {
	int key;
	Node *left;
	Node *right;
};

Node *createNode(int x) {
	Node *p = new Node;
	p->key = x;
	p->left = p->right = NULL;
	return p;
}

void Insert(Node *&root, int x) {
	if(root == NULL)
	{
		root = createNode(x);
		return;
	}
	if(x > root->key) {
		Insert(root->right);
	}
	else if(x < root->key) {
		Insert(root->left);
	}
	else return;
}
bool areIdentical(node * root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
 
    if (root1 == NULL || root2 == NULL)
        return false;
    return (root1->data == root2->data &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right));
}
 
bool isSubtree(node *T, node *S)
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


int main() {
	return 0;
}
