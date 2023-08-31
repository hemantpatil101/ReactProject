#include<bits/stdc++.h>
const int N=1e6+1;
const long long INF=1e18;
using namespace std;

vector<long long> dp(N,INF);

int main()
{
    long long n;
    cin>>n;

    long long int A[n+1];
    long long int dp[n+1][3] = {0};
    for(int i=0;i<n;i++)
    cin>>A[i];
    
    
    for(int i=1;i<=n;i++)
    {
        if(A[i-1]==0)
        {
            dp[i][0]= max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        }
        else if(A[i-1]==1)
        {
           dp[i][0]= max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
           dp[i][1] = 1 + max(dp[i-1][0],dp[i-1][2]);
        }
        else if(A[i-1]==2)
        {
           dp[i][0]= max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
           dp[i][2] = 1 + max(dp[i-1][0],dp[i-1][1]);
        }
        else
        {
           dp[i][0]= max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
           dp[i][1] = 1 + max(dp[i-1][0],dp[i-1][2]);
           dp[i][2] = 1 + max(dp[i-1][0],dp[i-1][1]);
        }
    }
    cout<<n-max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
}