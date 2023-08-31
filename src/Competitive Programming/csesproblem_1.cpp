#include<bits/stdc++.h>
using namespace std;

long long int dp[1000005]={0};
int main()
{
    long long int n;
    cin>>n;
    long long mod=1e9+7;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(j>i)
            break;
            dp[i] = (dp[i] + dp[i-j]) % mod;
        }
    }
    cout<<dp[n]<<endl;
}