#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int> adj[N];
int vis[N]={0};
//TIME COMPLEXITY O(VERTEX + EDGES)
void dfs(int v)
{
    vis[v]=1;
    cout<<v<<endl;
    /*TAKE ACTION ON VERTEX AFTER ENTERING THE VERTEX*/
    for(auto it:adj[v])
    {
        /*TAKE ACTION ON CHILD NODE BEFORE ENTERING CHILD NODE*/
        if(!vis[it])
        dfs(it);
        /*TAKE ACTION ON CHILD AFTER EXITING CHILD NODE*/
    }
    /*TAKE ACTION ON VERTEX BEFORE EXITING THE VERTEX*/
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
    dfs(1);

}
