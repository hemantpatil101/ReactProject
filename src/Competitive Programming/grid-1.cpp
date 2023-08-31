#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    
    int dp[n+1][k+1] = {0};
    dp[1][1] = 1;
    

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if((i==0 ) || (j==0 ))
            dp[i][j]=0;
            /*else if(i!=1 && j!=1)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];*/
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i==1 && j==1)
            dp[i][j] = 1;
            else if(A[i-1][j-1]=='#')
            dp[i][j]=0;
            else
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            cout<<i<<j<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            cout<<dp[i][j];
        }
        cout<<endl;
    }
    
    cout<<dp[n][k];
    return 0;
}
