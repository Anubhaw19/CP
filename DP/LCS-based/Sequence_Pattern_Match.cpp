#include <bits/stdc++.h>
using namespace std;
//Sequence pattern Matching
/*
input: 
string A="AXY"
String B="AOXCPY"

Stirng B contains String A.  (true)


output:
TRUE
**/
bool LCS(string x, string y, int n, int m)
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
    if(t[n][m]==n || t[n][m]==m)   //whether string A contains B or vice-versa
    return true;
    else
    return false;
}
int main()
{
    string x,y;
    cin >> x>>y;
    int n = x.length();
    int m=y.length();

    cout << LCS(x, y, n, m);
    return 0;
}
