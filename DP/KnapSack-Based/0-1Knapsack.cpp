#include<bits/stdc++.h>
using namespace std;
// memoization
int knapsack(int W,int n,int val[], int wt[],vector<vector<int>> t)
{
if(W==0 || n==0)
 return 0;
 if(t[n][W]!=-1)
 return t[n][W];
 else
 {
     if(W>=wt[n-1])
     return t[n][W]=max(val[n-1]+knapsack(W-wt[n-1],n-1,val,wt,t),knapsack(W,n-1,val,wt,t));
     else
     return t[n][W]=knapsack(W,n-1,val,wt,t);
 }

}

int main()
{
int n,W;
cin>>n>>W;
int val[n], wt[n];
for(int i=0;i<n;i++)
cin>>val[i];
for(int i=0;i<n;i++)
cin>>wt[i];

vector<vector<int>> t(n+1,vector<int>(W+1,-1));

 cout<<knapsack(W,n,val,wt,t);


    return 0;
}
