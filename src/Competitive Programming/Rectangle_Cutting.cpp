#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int dp[a+1][b+1];
    int n = a;
    int m = b;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==j)
            dp[i][j]=0;
            else
            {
                int ans = 1e9;
                for(int f=1;f<i;f++)
                {
                    ans = min(ans,1 + dp[i-f][j] + dp[f][j]);
                }
                for(int f=1;f<j;f++)
                {
                    ans = min(ans,1 + dp[i][j-f] + dp[i][f]);
                }
                dp[i][j] = ans;
            }
        }
    }
    cout<<dp[n][m];
}