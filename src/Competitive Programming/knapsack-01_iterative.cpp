
#include<bits/stdc++.h>
using namespace std;



class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
         int dp[n+1][W+1];
         
         
         for(int i=0;i<=n;i++)
         {
             for(int j=0;j<=W;j++)
             {
                 if(i==0 || j==0)
                 dp[i][j]=0;
                 else if(wt[i-1]<=W)
                 {
                     dp[i][j] = max(dp[i-1][W], dp[i-1][W-wt[i-1]] + val[i-1]);
                 }
                 else
                 dp[i][j] = dp[i-1][W];
             }
         }
         
         return dp[n][W];
    }
};



int main()
 {
    
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
