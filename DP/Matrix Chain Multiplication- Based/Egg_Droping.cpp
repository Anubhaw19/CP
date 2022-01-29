#include <bits/stdc++.h>
using namespace std;
int static t[11][51]; // 0<e<1=0 , 0<=f<=50
/*
EGG Droping Problem

What is the least number of egg-droppings that is guaranteed to work in all cases? 
The problem is not actually to find the critical floor,
 but merely to decide floors from which eggs should be dropped so that the total number of trials are minimized.

**/

int solve(int e, int f)
{
    if (f == 0 || f == 1 || e == 1) // if floor ==0 or 1 or egg==1 return floor
        return f;

    if (t[e][f] != -1)
        return t[e][f];

    int m = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int c1, c2;
        if (t[e - 1][k - 1] != -1)
            c1 = t[e - 1][k - 1];
        else
        {
            c1 = solve(e - 1, k - 1);
            t[e - 1][k - 1] = c1;
        }
        if (t[e][f - k] != -1)
            c2 = t[e][f - k];
        else
        {
            c2 = solve(e, f - k);
            t[e][f - k] = c2;
        }

        // int temp = 1 + max(solve(e - 1, k - 1), solve(e, f - k));
        int temp = 1 + max(c1, c2); // as calculating minimum no. of attempts for worst case (that's why max())

        m = min(m, temp);
    }
    return t[e][f] = m;
}

int main()
{
    memset(t, -1, sizeof(t));
    int egg, floor;

    cin >> egg >> floor;
    cout << solve(egg, floor);

    return 0;
}
