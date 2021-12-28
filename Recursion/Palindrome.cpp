#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
void solve(int arr[], int i, int n)
{
    swap(arr[i], arr[n - i - 1]);
    if (i >= n - i - 1)
        return;
    solve(arr, i + 1, n);
}

int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
