#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    long long  M = 1e9 + 7;
    int ch=0;
    int p = (n*(n+1))/2;
    if(p%2)
    ch=1;
    p = p/2;
    vector<vector<long long >> dp(p+1,vector<long long>(n+1));
    for(int i=0;i<=p;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
            dp[i][j] = 1;
            else if(j==0)
            dp[i][j] = 0;
            else if(j<=i)
            {
                dp[i][j] = (dp[i-j][j-1] + dp[i][j-1])%M;
            }
            else
            dp[i][j] = dp[i][j-1];
        }
    }
    
    if(ch)
    cout<<"0";
    else
    cout<<(dp[p][n] * 500000004)%M;
}