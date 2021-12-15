#include <bits/stdc++.h>
using namespace std;
// TOP-DOWN
int knapsack(int W, int n, int val[], int wt[])
{
    vector<vector<int>> t(n + 1, vector<int>(W + 1));
    //initiallisation
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 0;
    }
    for (int i = 0; i < W + 1; i++)
    {
        t[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (j >= wt[i - 1])
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][W];
}

int main()
{
    int n, W;
    cin >> n >> W;
    int val[n], wt[n];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << knapsack(W, n, val, wt);

    return 0;
}
