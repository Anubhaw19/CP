#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node *left;
	Node *right;
};

Node *createNode(int value)
{
	Node *newnode = new Node();
	if (!newnode)
	{
		cout << "Memory error\n";
		return NULL;
	}
	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
Node *insertNode(Node *root, int number)
{
	if (root == NULL)
	{
		root = createNode(number);
		/* or  root=createNode(value)*/
		return root;
	}
	/** Level oder traversal (BFS) until we find an empty place, i.e .
	either left child or right child of some node is pointing to NULL.*/
	queue<Node *> q;
	q.push(root);

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		if (temp->left != NULL)
			q.push(temp->left);
		else
		{
			temp->left = createNode(number);
			return root;
		}
		if (temp->right != NULL)
			q.push(temp->right);
		else
		{
			temp->right = createNode(number);
			return root;
		}
	}
	return root;
}
// Inorder Tarversal of a Binary Tree
void inorder(Node *temp)
{

	if (temp == NULL)
		return;

	inorder(temp->left);
	cout << temp->data << endl;
	inorder(temp->right);
}

int main()
{
	Node *root = createNode(10);
	root->left = createNode(11);
	root->left->left = createNode(7);
	root->right = createNode(9);
	root->right->left = createNode(15);
	root->right->right = createNode(8);

	inorder(root);
	cout << "*******" << endl;

	root = insertNode(root, 102);

	inorder(root);
}
