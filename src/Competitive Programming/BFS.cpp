#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> adj[N];
vector<int> vis(N,0);
vector<int> level(N,0);
void BFS(int source)
{
   queue<int> q;
   q.push(source);

   while(!q.empty())
   {
        int node = q.front();
        cout<<node<<endl;
        q.pop();
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
                level[it] = level[node] + 1;
            }    
        }
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
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            BFS(i);
        }    
    }
}