#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    int M = 1e9 + 7;
    cin>>n>>m;
    int A[n+1];
    for(int i=1;i<=n;i++)
    cin>>A[i];
    
    long long dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1)
            {
                if(A[i]==0 || A[i]==j)
                dp[i][j]=1;
                else
                dp[i][j]=0;
            }
            else
            {
                if(A[i]==0 || A[i]==j)
                {
                    dp[i][j]= ((dp[i-1][j-1]%M) + (dp[i-1][j]%M) + (dp[i-1][j+1]%M))%M;
                }
                else
                dp[i][j]=0;
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=m;i++)
    ans = (ans + dp[n][i])%M;
    cout<<ans;
    return 0;
}
