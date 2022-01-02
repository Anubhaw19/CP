#include<bits/stdc++.h>
using namespace std;
 //coin change problem: (maximum number of ways) /unbounded knapsack.
int maxWays(int n, int s,int c[])
{
   int t[n+1][s+1];
   for(int i=0;i<s+1;i++)
   t[0][i]=0;
   for(int i=0;i<n+1;i++)
   t[i][0]=1;

   for(int i=1;i<n+1;i++)
   {
       for(int j=1;j<s+1;j++)
       {
           if(j>=c[i-1])
           t[i][j]=t[i][j-c[i-1]] + t[i-1][j];
           else
           t[i][j]=t[i-1][j];
       }
   }
   return t[n][s];
}

int main()
{
 int n,sum;
 cin>>n>>sum;
 int coin[n];
 for(int i=0;i<n;i++)
 {
     cin>>coin[i];
 }

cout<<maxWays(n,sum,coin);
    return 0;

}
