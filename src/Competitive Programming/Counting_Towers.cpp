#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<long int>> dp(1000001,vector<long int>(2));
    dp[1][0] = 1;
    dp[1][1] = 1;
    const long long int M=1e9+7;
    /*int M = 1e9 + 7;*/
    for(int i=2;i<1000001;i++)
    {
        dp[i][0] = ((4*dp[i-1][0])%M + dp[i-1][1]%M)%M;
        dp[i][1] = ((2*dp[i-1][1])%M + dp[i-1][0]%M)%M;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long ans = (dp[n][0] + dp[n][1])%M;
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}
