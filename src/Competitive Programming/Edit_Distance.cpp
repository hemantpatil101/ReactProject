#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();

    int dp[n+1][m+1];
    for(int i=n;i>=0;i--)
    {
        for(int j=m;j>=0;j--)
        {
            if(i==n || j==m)
            dp[i][j] = max(m-j,n-i);
            else if(s1[i]==s2[j])
            dp[i][j] = dp[i+1][j+1];
            else 
            {
                int op1 = 1 + dp[i+1][j];
                int op2 = 1 + dp[i][j+1];
                int op3 = 1 + dp[i+1][j+1];
                dp[i][j] = min(op1,min(op2,op3));
            }
        }
    }
    cout<<dp[0][0];
}