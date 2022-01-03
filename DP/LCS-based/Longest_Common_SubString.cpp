#include <bits/stdc++.h>
using namespace std;
// {TOP-DOWN}
// LCS (longest Common SubString)
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
                t[i][j] = 0;
        }
    }
    int max = INT_MIN;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (max < t[i][j])
                max = t[i][j];
        }
    }
    return max;
}
int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.length();
    int m = y.length();

    cout << LCS(x, y, n, m);
    return 0;
}
