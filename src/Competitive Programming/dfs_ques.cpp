#include<bits/stdc++.h>
using namespace std;
int ans;
void dfs(int pt,int par,vector<vector<pair<int,int>>> &vp,int parin,int itr,vector<int> &vis)
{
    ans = max(ans,itr);
    for(auto it:vp[pt])
    {
        if(vis[it.first]==0 && it.first!=par)
        {
            if(parin>it.second)
            dfs(it.first,pt,vp,it.second,itr + 1,vis);
            else
            dfs(it.first,pt,vp,it.second,itr,vis);
        }
    }
}

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<pair<int,int>>> vp(n+1);
        
        vector<int> vis(n+1,0);
        for(int i=0;i<n-1;i++)
        {
            int p,q;
            cin>>p>>q;
            vp[p].push_back({q,i});
            vp[q].push_back({p,i});
        }
        ans=0;
        dfs(1,-1,vp,-1,1,vis);
        cout<<ans<<endl;
    }
    
}