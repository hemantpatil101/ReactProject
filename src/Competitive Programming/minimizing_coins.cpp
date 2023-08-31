#include<bits/stdc++.h>
using namespace std;

int solve(int n,int sum,vector<int> &dp,int A[])
{
    dp[0]=0;
    for(int i=1;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-A[j]>=0)
            {
                dp[i] = min(1 + dp[i-A[j]],dp[i]);
            }
        }
    }
    return dp[sum];
}
int main()
{
    int n,sum;
    cin>>n>>sum;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];

    vector<int> dp(sum+1,1e9);

    if(solve(n,sum,dp,A)>=1e9)
    cout<<"-1\n";
    else 
    cout<<solve(n,sum,dp,A);
}