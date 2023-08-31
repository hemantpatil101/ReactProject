#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int mod = 1e9 + 7;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    if(v[0][0]!='*')
    dp[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1 && j==1)
            continue;
            if(v[i-1][j-1]=='*')
            dp[i][j]=0;
            else
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
        }
    }
    cout<<dp[n][n];
}