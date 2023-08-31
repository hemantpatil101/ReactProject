#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;


//IN THIS QUESTION WE WILL BE GIVEN Q QUERIES(Q<=1e5)
//FOR EACH QUERY WE HAVE TO FIND SUM OF SUBTREE AND 
//NUMBER OF EVEN NUMBERS
vector<int> adj[N];
vector<int> sub_tree_sum(N,0);
vector<int> even_count(N,0);
int vis[N]={0};
//TIME COMPLEXITY O(VERTEX + EDGES)
void dfs(int v)
{
    vis[v]=1;
    /*TAKE ACTION ON VERTEX AFTER ENTERING THE VERTEX*/
    long long sum=0,cnt=0;
    for(auto it:adj[v])
    {
        /*TAKE ACTION ON CHILD NODE BEFORE ENTERING CHILD NODE*/
        if(!vis[it])
        {
            dfs(it);
            sum+=sub_tree_sum[it];
            cnt+=even_count[it];
        }    
        /*TAKE ACTION ON CHILD AFTER EXITING CHILD NODE*/
    }
    sub_tree_sum[v] = sum + v;
    if(v%2==0)
    cnt++;
    even_count[v] = cnt;
    /*TAKE ACTION ON VERTEX BEFORE EXITING THE VERTEX*/
}

int main()
{
    int n,m,q;
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
    {
        cout<<sub_tree_sum[i]<<" "<<even_count[i]<<endl; 
    }


}
