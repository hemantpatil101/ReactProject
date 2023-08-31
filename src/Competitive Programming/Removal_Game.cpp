#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];
    
    vector<vector<long long>> dp(n,vector<long long>(n));
    long long sum = 0;

    for(int i=0;i<n;i++)
    {
        sum +=A[i];
        dp[i][i] = A[i];
    }
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            long long ad = A[j] - dp[i][j-1];
            long long ut = A[i] - dp[i+1][j];
            dp[i][j] = max(ad,ut);
        }
    }
    cout<<(sum + dp[0][n-1])/2;
}