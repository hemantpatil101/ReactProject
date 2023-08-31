//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(int n,int sum,vector<int> &arr,int** dp)
    {
        if(dp[n][sum]!=-1)
        return dp[n][sum];
        if(sum==0)
        return 1;
        else if(n==0)
        return 0;
        else if(arr[n-1]<=sum)
        {
            return dp[n][sum] = solve(n-1,sum - arr[n-1],arr,dp) || solve(n-1,sum,arr,dp);
        }
        else
        return dp[n][sum] = solve(n-1,sum,arr,dp);
    }
    bool isSubsetSum(vector<int>arr, int sum)
    {
        int n = arr.size();
        int** dp;
        dp = new int*[n+1];
        
        for(int i=0;i<=n;i++)
        dp[i] = new int[sum+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            dp[i][j]=-1;
        }
        
        return solve(n,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends