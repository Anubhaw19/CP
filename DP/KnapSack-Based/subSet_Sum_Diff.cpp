#include <bits/stdc++.h>
using namespace std;
//minimum subset sum difference

int minSubSetSum(int n, int v[],int sum)
{
bool t[n+1][sum+1];
for(int i=0;i<sum+1;i++)
t[0][i]=false;
for(int i=0;i<n+1;i++)
    t[i][0]=true;

for(int i=1;i<n+1;i++)
{
    for(int j=1;j<sum+1;j++)
    {
        if(j>=v[i-1])
        {
            t[i][j]=t[i-1][j-v[i-1]] || t[i-1][j];
        }
        else
        t[i][j]=t[i-1][j];
    }
}    
vector<int> res;
for(int i=1;i<=sum/2;i++)
{
    if(t[n][i])
     res.push_back(i); // storing all possible sum of subset less than or equal to sum/2.
    cout<<"sum="<<i<<endl;
}
int m=INT_MAX;
for(auto x:res)
{ 
    /** subset_sum=s1 and s2 
     * let s2>s1 ,so s2-s1 = differnce beetween subsets
     * 0<=s1<=s2<=sum
     * s1+s2=sum
     * s2=sum-s1
     * therefore
     * s2-s1=>  sum-2*s1 ,
     * where s1<=sum/2.
    */
    m=min(m,sum-2*x);
}

return m;
}
int main()
{
int n,s=0;
cin>>n;
int v[n];
for(int i=0;i<n;i++)
{
cin>>v[i];
s+=v[i];
}

cout<<minSubSetSum(n,v,s);
return 0;
}
