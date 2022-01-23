#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001][2]; //either store the result in 3D array or in a hash_map

unordered_map<string, int> mp; // creating a map for storing the calculated result.

/* Boolean Parenthesization Problem:
   evalute expression to TRUE/(FALSE).

The given expression is "T | T & F ^ T", it evaluates true
in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)). 

   Symbols
    'T' ---> true 
    'F' ---> false 

    Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR 

I/O:
"T ^ F & T" 
-> it evaluates true in two ways "((T ^ F) & T)" and "(T ^ (F & T))"

O/P:
2
**/

int solve(string s, int i, int j, bool isTrue)
{
    if (i > j)
        return false; //return  0;
    if (i == j)
    {
        if (isTrue)
        {
            if (s[i] == 'T')
                return true; //return 1;
            else
                return false; // return 0;
        }
        else
        {
            if (s[i] == 'F')
                return true; //return 1;
            else
                return false; // return 0;
        }
    }
    string temp = to_string(i); //creating a key (temp) for the map  {"i j isTrue"  e.g:"2 5 1"}
    temp.append(" ");
    temp.append(to_string(j));
    temp.append(" ");
    temp.append(to_string(isTrue));

    if (mp.find(temp) != mp.end())
        return mp[temp];

    // if (t[i][j][isTrue] != -1)
    //     return t[i][j][isTrue];

    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int lt, lf, rt, rf;
        lt = solve(s, i, k - 1, true);  //   no. of ways left part true
        lf = solve(s, i, k - 1, false); //   no. of ways left part false
        rt = solve(s, k + 1, j, true);  //   no. of ways right part true
        rf = solve(s, k + 1, j, false); //   no. of ways right part false

        if (isTrue)
        {
            if (s[k] == '&')
                ans += lt * rt;
            else if (s[k] == '|')
                ans += lt * rt + lf * rt + lt * rf;
            else if (s[k] == '^')
                ans += lf * rt + lt * rf;
        }
        else // istrue= flase
        {
            if (s[k] == '&')
                ans += lf * rf + lf * rt + lt * rf;
            else if (s[k] == '|')
                ans += lf * rf;
            else if (s[k] == '^')
                ans += lf * rf + lt * rt;
        }
    }
    // return t[i][j][isTrue] = ans;
    return mp[temp] = ans;
}

int main()
{
    // memset(t, -1, sizeof(t));
    mp.clear();
    string s;
    cin >> s;
    
    bool isTrue = true;
    cout << solve(s, 0, s.length() - 1, isTrue);

    return 0;
}
