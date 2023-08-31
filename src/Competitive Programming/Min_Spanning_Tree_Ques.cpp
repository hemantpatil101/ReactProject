#include<bits/stdc++.h>
const int N = 2e3+10;
using namespace std;

vector<int> parent(N);
vector<int> sizz(N);
void make(int v)
{
    parent[v]=v;
    sizz[v]=1;
}
int find(int v)
{
    if(parent[v]==v)
    return v;
    return parent[v] = find(parent[v]);
}
void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        if(sizz[a]<sizz[b])
        swap(a,b);
        parent[b]=a;
        sizz[a]+=sizz[b];
    }
}


int main()
{
    int n,m;
    cin>>n;
    vector<pair<int,int>> cord(n+1);
    int u,v,w;
    
    for(int i=1;i<n+1;i++)
    {
        cin>>cord[i].first>>cord[i].second;
        
    }
    vector<pair<long long int,pair<int,int>>> edges;
    for(int i=1;i<=n;i++)
    {
        cin>>w;
        edges.push_back({w,{0,i}});
    }
    
    vector<int> c(n+1);
    for(int i=1;i<=n;i++)
    cin>>c[i];
    
   

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            long long g = abs(cord[i].first-cord[j].first) + abs(cord[i].second - cord[j].second);
            
            long long h = g*(c[i]+c[j]);
            edges.push_back({h,{i,j}});
        }
    }
    for(int i=0;i<=n;i++)
    make(i);

    sort(edges.begin(),edges.end());
    long long int totalcost=0;
    vector<int> power;
    vector<pair<int,int>> connections;
    for(auto it:edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        /*cout<<u<<" "<<find(u)<<" "<<v<<" "<<find(v)<<endl;*/
        if(find(u)==find(v))
        continue;

        Union(u,v);
        totalcost+=wt;
        if(u==0 || v==0)
        power.push_back(max(u,v));
        else
        connections.push_back({u,v});
        
    }
    cout<<totalcost<<endl;
    cout<<power.size()<<endl;
    for(auto it:power)
    cout<<it<<" ";
    cout<<endl;
    cout<<connections.size()<<endl;
    for(auto it:connections)
    cout<<it.first<<" "<<it.second<<endl;

}