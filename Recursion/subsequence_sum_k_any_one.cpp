// Printing any 1 subsequences with sum k
#include <bits/stdc++.h>
using namespace std;
//TC- O(n*2^n), SC - O(N)
bool printF(vector<int> arr, int n, vector<int> &ds, int ind, int sum, int k)
{
    if (ind == n)
    {
        if (sum == k)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        else return false;
    }
    if(printF(arr, n, ds, ind + 1, sum, k) == true) return true;
    ds.push_back(arr[ind]);
    sum+=arr[ind];
    if(printF(arr, n, ds, ind + 1, sum, k) == true) return true;
    ds.pop_back();
    sum-=arr[ind];
    return false;
}
int main()
{
    int n, ind = 0, sum = 0, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> ds;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printF(arr, n, ds, ind, sum, k);
    return 0;
}