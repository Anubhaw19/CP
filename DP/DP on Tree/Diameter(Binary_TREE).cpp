#include <bits/stdc++.h>
using namespace std;
int static t[11][51]; // 0<e<1=0 , 0<=f<=50
/*
Diameter of a Binary Tree
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

    int l = solve(root->left, res);  //length of left sub-Tree
    int r = solve(root->right, res); //length of right sub-Tree

    int temp = 1 + max(l, r);       // if current node is not the root node for the diameter of the tree
    int ans = max(temp, 1 + l + r); // if current node is the root node for the diameter of the tree
    res = max(res, ans);

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
