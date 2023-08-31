#include<bits/stdc++.h>
const int N = 1e5+5;
const int INF = 1e9;
using namespace std;
vector<pair<int,int>> adj[N];
vector<int> level(N,INF);

void BFS()
{
   deque<int> q;
   q.push_front(1);
   level[1]=0;
   while(!q.empty())
   {
      int node = q.front();
      q.pop_front();

      for(auto it:adj[node])
      {
         int v = it.first;
         int wt = it.second;
         /*cout<<v<<endl;*/
         if(level[node] + wt < level[v])
         {
            level[v] = level[node] + wt;
            if(wt==1)
            q.push_back(v);
            else
            q.push_front(v);
         }
      }
   }
}
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back({b,0});
        adj[b].push_back({a,1});
    }
    BFS();
    if(level[n]<INF)cout<<level[n];
    else 
    cout<<"-1\n";
}