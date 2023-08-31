#include<bits/stdc++.h>
using namespace std;

int dp[100000];
int func(int a,int A[])
{
    int cost=INT_MAX;
    if(a==0)
    return 0;
    if(dp[a]!=-1)
    return dp[a];
    cost = min(cost,func(a-1,A) + abs(A[a]- A[a-1]));
    if(a>1)
    cost = min(cost,func(a-2,A) + abs(A[a]- A[a-2]));

    return dp[a]=cost;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];

    cout<<func(n-1,A)<<endl;

}