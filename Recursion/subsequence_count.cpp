// Printing any 1 subsequences with sum k
#include <bits/stdc++.h>
using namespace std;
// TC - O(2^n)
int printF(vector<int> arr, int n, int ind, int sum, int k)
{
    if (ind == n)
    {
        if (sum == k)
        {
            return 1;
        }
        else return 0;
    }
    int l = printF(arr, n, ind + 1, sum, k);
    sum+=arr[ind];
    int r = printF(arr, n, ind + 1, sum, k);
    sum-=arr[ind];
    return l+r;
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
    cout<<printF(arr, n, ind, sum, k)<<endl;
    return 0;
}