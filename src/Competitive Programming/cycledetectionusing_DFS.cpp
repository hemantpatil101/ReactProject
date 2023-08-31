#include<bits/stdc++.h>
const int N = 1e5 + 10;
using namespace std;

vector<int> vis(N,0);
vector<int> adj[N];
bool Iscycle_DFS(int v,int par)
{
   vis[v]=1;
   for(auto it:adj[v])
   {
      if(vis[it] && it!=par)
      return true;
      if(!vis[it])
      Iscycle_DFS(it,v);
   }
   
}

int main()
{
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt=0;
    int ch=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {  
            if(Iscycle_DFS(i,-1))
            ch=1;
        }
    }
    if(ch)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}