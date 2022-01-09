#include <bits/stdc++.h>
using namespace std;
// Minimum nuber of insertion and deletion to convert string A to string B
/*
 A=heal
 B=pea

 insertion=1 (i.e ='p')
 deletion=2   (i.e='h','l')

 LCS(longest common subsequence):2  (i.e="ea")

 minimum number of:
 deletion = n-LCS; (n=length of string A)
 insertion = m- LCS; (m=length of string B)
**/  
void LCS(string x, string y, int n, int m)
{
    int t[n + 1][m + 1];
    //initialisation
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 0;
    for (int i = 0; i < m + 1; i++)
        t[0][i] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }
    }

    int LCS=t[n][m];
    cout<<LCS<<endl;
    cout<<"deletion :"<<n-LCS<<endl;
    cout<<"insertion :"<<m-LCS;
   
   
}
int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.length();
    int m = y.length();

    LCS(x, y, n, m);
    return 0;
}
