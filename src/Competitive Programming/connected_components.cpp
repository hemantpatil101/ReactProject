#include<bits/stdc++.h>
const int N=1e5+10;
using namespace std;

vector<int> vis(N,0);
vector<int> adj[N];
vector<vector<int>> vectorofcomponents;
vector<int> components;
void dfs(int v)
{
    vis[v]=1;
    components.push_back(v);
    for(auto it:adj[v])
    {
        if(!vis[it])
        dfs(it);
    }
}
 
int main()
{
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
           cnt++;
           components.clear();
           dfs(i);
           vectorofcomponents.push_back(components);
        }
    }
    cout<<cnt<<endl;
    cout<<vectorofcomponents.size()<<endl;
    for(auto i:vectorofcomponents)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }
}