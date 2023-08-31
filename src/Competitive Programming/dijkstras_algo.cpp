#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<pair<int,int>> vp[N];
//ONE SOURCE MULTIPLE DESTINATIONS AND EDGES ARE WEIGHTED
void dijkstras(int source)
{
   vector<int> vis(N,0);
   vector<int> dist(N,INT_MAX);
   set<pair<int,int>> st;
   st.insert({0,source});

   while(st.size()>0)
   {
      auto node = *(st.begin());
      st.erase(st.begin());
      int v = node.second;
      int dis = node.first;
      if(vis[v])
      continue;
      vis[v]=1;
      for(auto it:vp[v])
      {
         int child = it.first;
         int wt = it.second;
         if(dist[v] + wt< dist[child])
         {
            dist[child] = dist[v] + wt;
            st.insert({dist[child],child});
         }
      }
   }
}
int main()
{
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {
      int x,y,wt;
      cin>>x>>y,wt;
      vp[x].push_back({y,wt});
   }
}