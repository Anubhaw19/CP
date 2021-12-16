#include <bits/stdc++.h>
using namespace std;
// Equal Sum Partition Problem

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
    int n, sum = 0;
    cin >> n;

    int val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        sum += val[i];
    }
    if (sum % 2 != 0)
        cout << false;
    else
        cout << subSetSum(n, val, sum / 2);
    return 0;
}
