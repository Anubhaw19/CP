#include <bits/stdc++.h>
using namespace std;
int t[1001][1001];
/* Matrix Chain Multiplication [Memoization Bottom-UP]

STEPS:
   1. find i & j            (e.g: i=1 & j=n-1)
   2. find base condition   (e.g: i>=j)
   3. find k loop scheme    (e.g: k=i to k=j-1  ||  k=i+1 to k=j)
   4. calculate the temp ans(e.g:  temp =solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[k]*a[k])
                        or  (e.g:  temp =solve(a,i,k-1)+solve(a,k,j)+a[i-1]*a[k]*a[k])

**/

int solve(int a[], int i, int j)
{
     
    if (i >= j)
        return 0;

    if(t[i][j]!=-1)
    return t[i][j];

    int m = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int temp = solve(a, i, k) + solve(a, k + 1, j) + a[i - 1]*a[k]*a[j];
        m = min(m, temp);
    }
    return t[i][j]=m;
}


int main()
{
    memset(t,-1,sizeof(t));
    int a[5] = {1,2,3,4,5};

    cout<< solve(a, 1, 4);  // int i=1;j=n-1; solve(a,i,j); 

    return 0;
}
