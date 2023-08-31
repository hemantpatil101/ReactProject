#include<bits/stdc++.h>
using namespace std;
int N;
int dp[100002][4];
int solve(int n,int prev,vector<vector<int>> &A)
{
    if(n==N)
    return 0;
    if(dp[n][prev]!=-1)
    return dp[n][prev];
    int mx=0;
    if(prev==0)
    {
        mx = max(mx,A[n][1] + solve(n+1,1,A));
        mx = max(mx,A[n][2] + solve(n+1,2,A));
        mx = max(mx,A[n][3] + solve(n+1,3,A));
    }
    else if(prev == 1)
    {
        mx = max(mx,A[n][2] + solve(n+1,2,A));
        mx = max(mx,A[n][3] + solve(n+1,3,A));
    }
    else if(prev==2)
    {
        mx = max(mx,A[n][1] + solve(n+1,1,A));
        mx = max(mx,A[n][3] + solve(n+1,3,A));
    }
    else
    {
        mx = max(mx,A[n][1] + solve(n+1,1,A));
        mx = max(mx,A[n][2] + solve(n+1,2,A));
    }
    return dp[n][prev] = mx;
}

int main()
{    
    cin>>N;
    vector<vector<int>> A(N,vector<int>(4,0));
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++)
    cin>>A[i][1]>>A[i][2]>>A[i][3];

    cout<<solve(0,0,A);
    return 0;
}