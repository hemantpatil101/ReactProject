#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    int n,m;
    cin>>s1>>s2;
    n = s1.size();
    m = s2.size();

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    //To print largest common subsequence

    string lcs = "";
    int i=n;
    int j=m;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            lcs = lcs + s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1])
        {
            i--;
        }
        else
        j--;
    }

    string ans;
    for(int i=lcs.size();i>=0;i--)
    ans = ans + lcs[i];

    cout<<ans<<endl;

    //To print shortest common supersequence

    string scss;
    i=n;
    j=m;
    while(i>=0 || j>=0)
    {
        if(s1[i-1]==s2[j-1])
        {
            scss = scss + s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1])
        {
            scss = scss + s1[i-1];
            i--;
        }
        else
        {
            scss = scss + s2[j-1];
            j--;
        } 
    }

    string ans1="";

    for(int i=scss.size();i>=0;i--)
    ans1 = ans1 + scss[i];

    cout<<ans1<<endl;
}