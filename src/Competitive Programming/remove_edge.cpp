const int  M = 1e9+7;


void DFS(int v,int par,vector<long long int>& subtree_sum,vector<int> adj[],vector<int>& A)
{    
    subtree_sum[v]+=A[v-1];
    for(auto it:adj[v])
    {
        
        if(it==par)continue;
        
        DFS(it,v,subtree_sum,adj,A);
        subtree_sum[v] += subtree_sum[it];
           
    }
    
}                          


int Solution :: deleteEdge(vector<int> &A, vector<vector<int> > &B)
{
    int n1 = A.size();
    vector<long long int> subtree_sum(n1+1,0);
    
    vector<int> adj[n1+1];
    for(auto it:B)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    DFS(1,0,subtree_sum,adj,A);
    
    
    long long temp = subtree_sum[1];
    
    long long ans=0;
    for(int i=2;i<=n1;i++)
    {
        long long s = subtree_sum[i];
        ans=max(ans,((temp-s)*1ll*(s)));
    }
    
    return ans%M;
}

