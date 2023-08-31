#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,h;
    cin>>n>>h;
    int A[n];
    int B[n];

    for(int i=0;i<n;i++)
    cin>>A[i];

    for(int i=0;i<n;i++)
    cin>>B[i];

    int dp[n+1][h+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=h;j++)
        {
            if(j==0 || i==0)
            dp[i][j]=0;
            else if(j>=A[i-1])
            {
                dp[i][j] = max(dp[i-1][j-A[i-1]] + B[i-1],dp[i-1][j]);
            }
            else 
            dp[i][j] = dp[i-1][j]; 
        }
    }
    cout<<dp[n][h];
}