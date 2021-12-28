#include <bits/stdc++.h>
using namespace std;

void print_subsequences(vector<int> arr, int n, int ind, vector<int> &ds)
{
    if (ind >= n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
        if (ds.size() == 0)
        {
            cout << "{}" << endl;
        }
        return;
    }
    print_subsequences(arr, n, ind + 1, ds);
    ds.push_back(arr[ind]);
    print_subsequences(arr, n, ind + 1, ds);
    ds.pop_back();
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> ds;
    print_subsequences(arr, n, 0, ds);
    return 0;
}