#include <bits/stdc++.h>
using namespace std;
int static t[11][51]; // 0<e<1=0 , 0<=f<=50
/*
Dynamic Programming on TREE: (General)
EX: diameter of  a Binary Tree

Steps:
1>Base Case
2>Hypothesis
3>Induction (temporary-answer, answer, result )
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
    if (root == nullptr) //BASE CASE
        return 0;

    int l = solve(root->left, res); //HYPOTHESIS
    int r = solve(root->right, res);

    //INDUCTION
    int temp = 1 + max(l, r);       //= calculate temp ans;
    int ans = max(temp, 1 + l + r); // ans= condition(temp,relation);
    res = max(res, ans);

    return temp;
}

int main()
{
    int res = INT_MAX;
    Node *r = NULL;
    //TODO: insert node in the tree
    cout << solve(r, res);

    return 0;
}
