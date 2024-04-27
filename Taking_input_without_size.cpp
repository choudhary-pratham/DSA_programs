#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<int> arr;
    string s;
    while (ss >> s)
    {
        int size = s.size(), i = 0, num = 0, negative = false;
        if (s[0] == '-')
        {
            negative = true;
            i++;
        }
        for (; i < size; i++)
        {
            num = num * 10 + (s[i] - '0');
        }
        if (negative == true)
            num = num * -1;
        arr.push_back(num);
    }
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
    return 0;
}
