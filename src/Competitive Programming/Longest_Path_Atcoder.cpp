#include<bits/stdc++.h>
using namespace std;
vector<int> dis(10010,-1);
vector<int> adj[10010];
int dfs(int node)
{
    if(dis[node]!=-1) return dis[node];
    int temp=0;
    for(auto it:adj[node])
    {
       if(dis[it]==-1)
       dfs(it);
       temp = max(temp,dis[it]+1);
    }
    return dis[node] = temp;
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    
    vector<int> dist(n+1,0);
    for(int i=0;i<m;i++)
    {
       cin>>a>>b;
       adj[a].push_back(b);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans = max(ans,dfs(i));
    }
    cout<<ans<<endl;
}