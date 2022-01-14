#include <bits/stdc++.h>
using namespace std;
// Minimum  number of deletion to make it Palindromic String
/*
input: 
string A="agbcba";
minimum number of deletion (or Insertion) for making palindrominc string : 1 (i.e :'g')
palindromic string after minimum deletion ="abcba" (i.e : longest palindromic subsequence)

output:
1

solution:
string A="agbcba"
reverse of A= "abcbga"  //2nd string
minimum no. of deletion =n-LCS (n=length of string)

**/
int LCS(string x, string y, int n, int m)
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

    return n-t[n][m];
}
int main()
{
    string x;
    cin >> x;
    int n = x.length();
    string y = string(x.rbegin(), x.rend());

    cout << LCS(x, y, n, n);
    return 0;
}
