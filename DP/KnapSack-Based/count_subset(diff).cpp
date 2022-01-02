#include<iostream>
using namespace std;
 // count the number of subsets with given difference
int countSubSet(int n, int sum,int v[])
{
int t[n+1][sum+1];

for(int i=0;i<sum+1;i++)
 t[0][i]=0;

for(int i=0;i<n+1;i++)
     t[i][0]=1;

     for(int i=1;i<n+1;i++)
     {
         for(int j=1;j<sum+1;j++)
         {
             if(j>=v[i-1])
             t[i][j]=t[i-1][j-v[i-1]]+t[i-1][j];
             else
             t[i][j]= t[i-1][j];
         }
     }
     
     return t[n][sum];
}



int main()
{
    int n,d,sum=0;
     cin>>n>>d;
     int v[n];
     for(int i=0;i<n;i++)
     {
         cin>>v[i];
         sum+=v[i];
     }
     int s=(sum+d)/2;
     
     cout<<countSubSet(n,s,v);
    return 0;
}


