#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;


//TO FIND DIAMETER WE USE CONCEPT OF DEPTH OF TREE
vector<int> adj[N];

vector<int> depth(N,0);
int vis[N]={0};
//TIME COMPLEXITY O(VERTEX + EDGES)
void dfs(int v)
{
    vis[v]=1;
    /*TAKE ACTION ON VERTEX AFTER ENTERING THE VERTEX*/
    for(auto it:adj[v])
    {
        /*TAKE ACTION ON CHILD NODE BEFORE ENTERING CHILD NODE*/
        if(!vis[it])
        {
            depth[it] = depth[v]+1;
            dfs(it);
        }    
        /*TAKE ACTION ON CHILD AFTER EXITING CHILD NODE*/
    }
    /*TAKE ACTION ON VERTEX BEFORE EXITING THE VERTEX*/
}


int main()
{
    int n;
    cin>>n;
    int a,b;

    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }
    dfs(1);
    int mx_dep=0,in;
    for(int i=1;i<=n;i++)
    {
       if(mx_dep<depth[i])
       {
          mx_dep=depth[i];
          in=i;
       }
       depth[i]=0;
       vis[i]=0;
    }
    dfs(in);
    
    mx_dep=0;
    for(int i=1;i<=n;i++)
    mx_dep = max(mx_dep,depth[i]);

    cout<<mx_dep<<endl;
}
