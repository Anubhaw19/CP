#include <bits/stdc++.h>
using namespace std;
// Print Shortest Common SuperSequence (SCS)
/*
input: 
string A="geeks";
string B="ekes"

Shortest Common SuperSequence ="geekes" or "gekeks" (LCS=3 i.e="eks" or "ees")


**/
string LCS(string x, string y, int n, int m)
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

    string s;
    int i = n, j = m;
    while (i != 0 && j != 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s += x[i - 1];
            i--;
            j--;
        }
        else
        {
            if (t[i][j - 1] > t[i - 1][j]) //change here "">="" for other SCS
            {
                s += y[j - 1];
            }
            else
            {
                s += x[i - 1];
                i--;
            }
        }
    }
    while (i)
    {
        s += x[i - 1]; //printing rest character of string x if (i!=0)
        i--;
    }
    while (j)
    {
        s += y[j - 1]; //printing rest character of string y if (j!=0)
        j--;
    }

    reverse(s.begin(), s.end());
    return s;
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
