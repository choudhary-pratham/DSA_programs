#include<bits/stdc++.h>
using namespace std;
int f(int n,vector<int>&dp)
{
    if(n<=1)
    {
        return n;
    }
    
    if(dp[n]!=-1) return dp[n];

    return dp[n] = f(n-1,dp) + f(n-2,dp);
}
int main()
{
    int n;
    cin>>n;
    //using memoization- computing from top to bottom.
    // TC-O(N)  , SC - O(N)+O(N)
    vector<int>dp(n+1,-1);
    cout<<f(n,dp)<<endl;
    
    //using tabulation: computing from bottom(base case) to the top
    // TC-O(N)  , SC - O(N)
    vector<int>dp(n+1,-1);
    dp[0] = 0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
    //optimising space complexity in tabualation
    // TC-O(N)  , SC - O(1)
    
    int curi=0,prev2 =0,prev1=1;
    for(int i=2;i<=n;i++)
    {
        curi = prev1+prev2;
        prev2=prev1;
        prev1 = curi;
    }
    cout<<prev1<<endl;
    return 0;
}