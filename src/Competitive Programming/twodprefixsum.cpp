#include<bits/stdc++.h>
using namespace std;

long long twodpresum(int a,int b,int c,int d,int n,int m,vector<vector<int>> &pf)
{

   return pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1];
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n+1,vector<int>(m+1));
    vector<vector<int>>pf(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<= m;j++)
        cin>>v[i][j];
    }
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
         pf[i][j] = v[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
      }
   }

   int a,b,c,d;
   cin>>a>>b>>c>>d;
   cout<<twodpresum(a,b,c,d,n,m,pf)<<endl;
}
//HERE BOTH pf & v  ARE HAVING 1 BASED INDEXING