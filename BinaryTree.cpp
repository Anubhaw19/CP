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
/* function to delete the given deepest node
(delNode) in binary tree */
void deleteNode(Node *root, Node *delNode)
{
	if (root == delNode)
	{
		root = NULL;
		delete (delNode);
		return;
	}
	queue<Node *> q;
	q.push(root);
	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		if (temp == delNode)
		{
			temp = NULL;
			delete (delNode);
			return;
		}
		if (temp->right)
		{
			if (temp->right == delNode)
			{
				temp->right = NULL;
				delete (delNode);
				return;
			}
			else
				q.push(temp->right);
		}
		if (temp->left)
		{
			if (temp->left == delNode)
			{
				temp->left = NULL;
				delete (delNode);
				return;
			}
			else
				q.push(temp->left);
		}
	}
}

//function to delete element in a Binary Tree
Node *deletion(Node *root, int value)
{
	if (root == NULL)
		return NULL;

	if (root->left == NULL && root->right == NULL && root->data == value)
		return NULL;

	queue<Node *> q;
	q.push(root);
	Node *temp;
	Node *delNode;

	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp->data == value)
			delNode = temp;
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	if (delNode) // i.e, delNode!=NULL
	{
		int x = temp->data;
		delNode->data = x;
		deleteNode(root, temp);
	}
	return root;
}
int main()
{
	Node *root = createNode(10);
	root->left = createNode(11);
	root->left->left = createNode(7);
	root->right = createNode(9);
	root->right->left = createNode(15);
	root->right->right = createNode(8);

	root = insertNode(root, 102);

	inorder(root);

	root = deletion(root, 102);
	cout << "*******" << endl;
	inorder(root);
}
