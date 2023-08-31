#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;


//DEPTH AND HEIGHT ARE CALCULATED IN TREE SO HERE WE DONT EVEN NEED
//VISITED ARRAY INSTEAD WE CAN JUST KEEP TRACK OF PARENT ELEMENT TO 
//AVOID LOOP BETWN TWO ELEMENTS...
vector<int> adj[N];
vector<int> height(N,0);
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
            height[v] = max(height[v],height[it]+1);
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
    for(int i=1;i<=n;i++)
    cout<<height[i]<<" "<<depth[i]<<endl;
}
