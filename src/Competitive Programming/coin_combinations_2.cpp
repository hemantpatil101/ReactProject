#include<bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;


int solve(int n,int sum,int A[],vector<vector<int>> &dp)
{
    if(dp[n][sum]!=-1)
    return dp[n][sum];
    if(sum==0)
    return 1;
    if(n==0)
    return 0;
    if(A[n-1]<=sum)
    return dp[n][sum] = (solve(n,sum - A[n-1],A,dp) + solve(n-1,sum,A,dp))%M;
    else 
    return dp[n][sum] = (solve(n-1,sum,A,dp))%M;
}
int main()
{
    int n,sum;
    cin>>n>>sum;

    /*vector<vector<int>> dp(n+1,vector<int>(sum+1));*/
    int dp[n+1][sum+1];
    int A[n+1];
    for(int i=1;i<=n;i++)
    cin>>A[i];
    A[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
            dp[i][j] = 1;
            else 
            {
                int op1 = 0;
                int op2 = 0;
                if(A[i]<=j)
                op1 = dp[i][j-A[i]];
                if(i>1)
                op2 = dp[i-1][j];

                dp[i][j] = (op1 + op2)%M;
            }
        }
    }
    /*cout<<solve(n,sum,A,dp);*/
    cout<<dp[n][sum];
}