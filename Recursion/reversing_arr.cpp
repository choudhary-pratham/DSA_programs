#include <bits/stdc++.h>
using namespace std;

bool solve(string str, int i, int n)
{
    if(i>=n/2) return true;
    if (str[i] != str[n - 1 -i])
        return false;
    return solve(str, i + 1, n);
}

int main()
{
    string str;
    cin >> str;
    cout << solve(str, 0, str.size()) << endl;
    return 0;
}
