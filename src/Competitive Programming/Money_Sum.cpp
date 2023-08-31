#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int A[n];
   for(int i=0;i<n;i++)
   cin>>A[i];

   int sum=0;
   for(int i=0;i<n;i++)
   sum+=A[i];
   set<int> st;

   /*vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));*/
   int dp[sum+1] = {-1};
   dp[0]=1;
   for(int i=1;i<=n;i++)
   {
       for(int j=sum;j>=0;j--)
       {
            if(j>=A[i-1])
            {
                if(dp[j-A[i-1]]==1)
                dp[j] = 1;
            }
       }
   }
       for(int j=1;j<=sum;j++)
       {
           if(dp[j]==1)
           st.insert(j);
       }
   cout<<st.size()<<endl;
   for(auto it:st)
   cout<<it<<" ";
}