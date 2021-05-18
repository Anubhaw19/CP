#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // constructors
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    Node()
    {
        left = NULL;
        right = NULL;
    }

    Node *insertNode(Node *root, int value)
    {
        if (root == NULL)
        {
            root = new Node(value);
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
                temp->left = new Node(value);
                return root;
            }
            if (temp->right != NULL)
                q.push(temp->right);
            else
            {
                temp->right = new Node(value);
                return root;
            }
        }
        return root;
    }
    // Inorder Tarversal of a Binary Tree
    void inorder(Node *root)
    {

        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
};

// Node* createNode(int value)
// {
// 	Node* newnode=new Node();
// 	if(!newnode)
// 	{
// 		cout<<"Memory error\n";
// 		return NULL;
// 	}
// 	newnode->data=value;
// 	newnode->left=newnode->right=NULL;
// 	return newnode;
// }

int main()
{

    Node *myroot = NULL;
    myroot = myroot->insertNode(myroot, 60);
    myroot = myroot->insertNode(myroot, 40);
    myroot = myroot->insertNode(myroot, 20);
    myroot = myroot->insertNode(myroot, 10);
    myroot->inorder(myroot);
    cout << "*******" << endl;

    myroot = myroot->insertNode(myroot, 102);

    myroot->inorder(myroot);
}
