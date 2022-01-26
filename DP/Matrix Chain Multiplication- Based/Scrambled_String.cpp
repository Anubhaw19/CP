#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> mp;
/*
SCRAMBLED STRING

Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.

    Below is one possible representation of str = “coder”:
 

    coder
   /    \
  co    der
 / \    /  \
c   o  d   er
           / \
          e   r

To scramble the string, we may choose any non-leaf node and swap its two children. 
Suppose, we choose the node “co” and swap its two children, it produces a scrambled string “ocder”.
 

    ocder
   /    \
  oc    der
 / \    /  \
o   c  d   er
           / \
          e   r
Thus, “ocder” is a scrambled string of “coder”.

Similarly, if we continue to swap the children of nodes “der” and “er”, it produces a scrambled string “ocred”.

**/

bool solve(string a, string b)
{
    if (a.length() != b.length())
        return false;
    if (a.compare(b) == 0) // both string are same
        return true;
    if (a.length() <= 1) // both are empty or string has only one and different character
        return false;

    string key = a + " " + b;
    if (mp.find(key) != mp.end())
        return mp[key];

    int n = a.length();
    bool flag = false;
    for (int i = 1; i < a.length(); i++)
    {
        // if swaped
        bool c1 = solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i));
        // if not swaped
        bool c2 = solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - i));

        if (c1 || c2)
        {
            flag = true;
            break;
        }
    }
    return mp[key] = flag;
}

int main()
{
    mp.clear();
    string a, b;
    cin >> a >> b;

    cout << solve(a, b);

    return 0;
}
