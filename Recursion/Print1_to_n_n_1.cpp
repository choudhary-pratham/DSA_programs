// #include<bits/stdc++.h>
// using namespace std;

// void solve(int n)
// {
//     if(n==1)
//     {
//     cout<<n<<" ";
//     return;
//     }
//     // cout<<n<<" "; // n-1;
//     solve(n-1);
//     cout<<n<<" "; // 1-n
// }

// int main(){
//     int n;
//     cin>>n;
//     solve(n);
//     return 0;
// }

// using Backtracking

#include<bits/stdc++.h>
using namespace std;

void solve(int i,int n)
{
    // Printing 1->N 
    // if(i<1)
    // {
    //     return;
    // }
    // solve(i-1,n);
    // cout<<i<<endl;

    //Printing N->1
    if(i>n)
    {
        return;
    }
    solve(i+1,n);
    cout<<i<<endl;
}

int main(){
    int n;
    cin>>n;
    solve(1,n);
    return 0;
}