#include<bits/stdc++.h>
using namespace std;

int dp[100000];

int func(int i,int k,int A[])
{
    int cost = INT_MAX;
    if(i==0)
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    for(int j=1;i-j>=0 && j<=k;j++)
    {
        cost = min(cost, func(i-j,k,A) + abs(A[i]-A[i-j]));
    }
    return dp[i] = cost;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];

    cout<<func(n-1,k,A)<<endl;
}