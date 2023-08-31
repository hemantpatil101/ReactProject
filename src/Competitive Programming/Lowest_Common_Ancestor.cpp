#include<bits/stdc++.h>
const int N = 1e5+10;
using namespace std;

vector<int> vis(N,0);
vector<int> adj[N];

//THIS IS AN O(n) ALGO BUT THERE ARE SOME OTHER APROACHES LIKE BINARY UPLIFTING THAT CAN CALCULATE IN O(LOG(n))

vector<int> parent(N,0);

void DFS(int v,int par)
{
    parent[v]=par; 
    for(auto it:adj[v])
    {
        if(it!=par)
        DFS(it,v);
    }
}
vector<int> give_path(int v)
{
    vector<int> ans;
    while(v!=-1)
    {
        ans.push_back(v);
        v=parent[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n,m;
    cin>>n;
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    } 
    
    cin>>a>>b;
    DFS(1,-1);
    vector<int> path_a = give_path(a);
    vector<int> path_b = give_path(b);
    int f=0;
    for(int i=0;i<min(path_a.size(),path_b.size());i++)
    {
       if(path_a[i]==path_b[i])
       f=path_a[i];
       else
       break;
    }
    cout<<f<<endl;
}