#include <bits/stdc++.h>
using namespace std;
// SubSet Sum Problem

bool subSetSum(int n, int val[], int sum)
{

    bool t[n + 1][sum + 1];
    for (int i = 0; i < sum + 1; i++)
    {
        t[0][i] = false;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = true;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (j >= val[i - 1])
                t[i][j] = t[i - 1][j] || t[i - 1][j - val[i - 1]];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}
int main()
{
    int n, sum;
    cin >> n;
    cin >> sum;
    int val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    cout << subSetSum(n, val, sum);
    return 0;
}
