#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    for(int i=1;i<=n;i++)
    dp[i] = 1e9;
    dp[0]=0;
    for(int i=0;i<=n;i++)
    {
        int j=i;
        while(j>0)
        {
            dp[i] = min(dp[i],1 + dp[i-j%10]);
            j = j/10;
        }
    }
    cout<<dp[n];
}