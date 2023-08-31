
#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    int solve(int n,int W,int wt[], int val[],int** dp)
    {
        if(n==0 || W==0)
        return 0;
        if(dp[n][W]!=-1)
        return dp[n][W];
        if(wt[n-1]<=W)
        {
            return dp[n][W] = max(val[n-1] + solve(n-1,W-wt[n-1],wt,val,dp),solve(n-1,W,wt,val,dp));
        }
        else
        return dp[n][W] = solve(n-1,W,wt,val,dp);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
         int** dp;
         dp = new int*[n+1];
         
         for(int i=0;i<=n;i++)
         dp[i] = new int[W+1];
         
         for(int i=0;i<=n;i++)
         {
             for(int j=0;j<=W;j++)
             dp[i][j]=-1;
         }
         return solve(n,W,wt,val,dp);
    }
};


int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
