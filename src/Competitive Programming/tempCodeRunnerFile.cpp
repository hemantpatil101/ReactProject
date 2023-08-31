#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ch=0;
    if(n%2)
    ch=1;
    /*int dp[n+1][2];
    dp[0][0]=0;
    dp[0][1]=0;
    for(int i=2;i<=n;i=i+2)
    {
        dp[i][0] = dp[i-2][0] + dp[i-2][1] + 1;
        dp[i][1] = dp[i-2][0] + dp[i-2][1] + 1;
    }*/
    int ans=1;
    for(int i=1;i<=n/2;i++)
    {
        ans = ans * 2;
    }
    if(ch)
    cout<<"0";
    else
    {
        cout<<ans;
    }
}