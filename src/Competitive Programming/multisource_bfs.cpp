#include<bits/stdc++.h>
using namespace std;
// THIS IS NOT EXACTLY  MULTI SOURCE BFS BUT ITS MORE OPTIMISED 
//THAN THAT WE CAN CALL IT MULTISOURCE DIJKSTRA'S

long long dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &roots)
{
    if(parent!=-1 && adj[node].size()==1)return (roots[node] = 1);
    else
    {
        for(auto it:adj[node])
        {
           if(it!=parent)
           {
              dfs(it,node,adj,roots);
              roots[node]+=roots[it];
           }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k,temp,temp1,qe;
        cin>>n;

        vector<int> roots(n+1,0);
        vector<int> parent(n+1,0);
        vector<vector<int>> adj(n+1,vector<int>());
        int a,b;
        queue<pair<int,int>> q;
        vector<int> vis(n+1,0);
        for(int i=0;i<n-1;i++)
        {
           cin>>a>>b;
           adj[a].push_back(b);
           adj[b].push_back(a);
        }
        vector<int> hem;
        for(int i=2;i<=n;i++)
        {
            if(adj[i].size()==1)
            {
                hem.push_back(i);
                roots[i]=1;
            }    
        }
        cin>>qe;
        vector<pair<int,int>> gh;
        for(int i=0;i<qe;i++)
        {
            cin>>a>>b;
            gh.push_back({a,b});
        }
    
        dfs(1,-1,adj,roots);
        /*while(q.size()>0)
        {
            int node = q.front().first;
            int par = q.front().second;
            parent[node]=par;
            q.pop();
            vis[node]++;
            for(auto it:adj[node])
            {
                if(it!=par && it!=1)
                {
                    q.push({it,node});
                    vis[it]++;
                }
            }

        }
        */
       /*
       while(q.size()>0)
       {
            int node = q.front().first;
            int par = q.front().second;
        
            q.pop();
            vis[node]++;
            for(auto it:adj[node])
            {
                if(it!=par && it!=1 && vis[it]==0)
                {
                    q.push({it,node});
                    vis[it]++;
                    roots[it] +=roots[node];
                }
                else if(vis[it]<adj[it].size())
                {
                    roots[it] +=roots[node];
                    vis[it]++;
                }
            }
       }*/
        /*for(int i=0;i<hem.size();i++)
        {
            int temp = hem[i];
            int p = temp;
            while(parent[temp]!=-1)
            {
                roots[parent[temp]]+=roots[p];
                temp = parent[temp];
            }
        }*/


        for(int i=0;i<qe;i++)
        {
            cout<<roots[gh[i].first]*1ll*roots[gh[i].second]<<endl;
        }    
        
    }
}