#include <bits/stdc++.h>
using namespace std;
int static t[11][51]; // 0<e<=10 , 0<=f<=50
/*
Binary Tree:
Maximum Path Sum | From any node to any node
**/

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    //TODO :  implement Constructor and Methods
};

int solve(Node *root, int &res)
{
    if (root == nullptr)
        return 0;

    int l = solve(root->left, res);  //Maximum Path Sum of left sub-Tree
    int r = solve(root->right, res); //Maximum Path Sum of right sub-Tree

    int temp = max(max(l, r) + root->data, root->data); // if current node is not the root node for the Maximum Path Sum
    int ans = max(temp, l + r + root->data);            // if current node is the root node for the Maximum Path Sum
    res = max(res, ans);

// if(temp>0)
// return temp;
// else
// return 0; 
    return temp;
}

int main()
{
    int res = INT_MIN;
    Node *r = NULL;
    //TODO: insert node in the tree
    cout << solve(r, res);

    return 0;
}
