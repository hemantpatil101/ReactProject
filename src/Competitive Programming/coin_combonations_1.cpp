#include<bits/stdc++.h>
using namespace std;

/*int solve(int n,int sum,vector<vector<int>> &dp,int A[])
{
    int mod = 1e9 + 7;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            
        }
    }
    return dp[n][sum];
}*/
int main()
{
    int n,sum;
    cin>>n>>sum;
    int mod = 1e9 + 7;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];

    int dp[sum+1] = {0};
    dp[0]=1;
    for(int i=1;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[j]<=i)
            {
                dp[i] = (dp[i] + dp[i - A[j]])%mod;
            }
        }
    }
    cout<<dp[sum];
}