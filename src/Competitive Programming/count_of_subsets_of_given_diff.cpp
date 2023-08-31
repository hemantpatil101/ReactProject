#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,diff;
    cin>>n>>diff;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];

    sort(A,A+n,greater<int>()); /*If zero is also present then it will handle it and give us right answer*/

    //Program to find number of subsets having difference equal to k
    
    int sum=0;
    for(int i=0;i<n;i++)
    sum = sum + A[i];

    int p = (sum + diff)/2;
    int dp[n+1][p+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=p;j++)
        {
            if(j==0)
            dp[i][j]=1;
            else if(i==0)
            dp[i][j]=0;
            else if(A[i-1]<=j)
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-A[i-1]]);
            else
            dp[i][j] =  dp[i-1][j];      
        }
    }
    cout<<dp[n][p];
}