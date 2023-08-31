#include<bits/stdc++.h>
const int M = 1e9+7;
using namespace std;
long long inv(long long i) 
{
  return i <= 1 ? i : M - (long long)(M/i) * inv(M % i) % M;
}


long long ncr(int n,int r)
{
   long long num=1;
   for(int i=1;i<=n;i++)
   {
      num = ((num % M) * i)%M;
   }

   long long den = 1;
   for(int i=1;i<=r;i++)
   den = ((den % M) * i)%M;
   
   
   long long invden = inv(den);
   long long ans = ((num%M)*(invden%M))%M;
   return ans%M;

}
void solve()
{
      int n;
      cin>>n;
      int A[n+1];
      int root;
      
      int Vis[n+1]={0};
      int Par[n+1]={0};
      int leaf[n+1]={0};
      for(int i=1;i<n+1;i++)
      {
         cin>>A[i];
         if(i==A[i])
         Par[i]=-1;
         else
         Par[i] = A[i];

         leaf[A[i]]=1;
      }
      if(n==1)
      {
         cout<<"1\n1\n1\n";
         cout<<endl;
         return;
      }
      vector<int> vec;
      for(int i=1;i<=n;i++)
      {
         if(leaf[i]==0)
         vec.push_back(i);
      }

      cout<<vec.size()<<endl;
      
      for(int i=0;i<vec.size();i++)
      {
         vector<int> ans;
         int cur = vec[i];

         while(cur!=-1 && !Vis[cur])
         {
            ans.push_back(cur);
            Vis[cur]=1;
            cur = Par[cur];
         }

         reverse(ans.begin(),ans.end());

         cout<<ans.size()<<endl;
         for(auto it:ans)
         cout<<it<<" ";
         cout<<endl;
         
      }
      cout<<endl;
      return;
}


int main()
{
   ios_base::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
      solve();
   }   
   return 0;
}