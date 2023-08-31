#include<bits/stdc++.h>
const int N = 1e5+10;
using namespace std;

//THIS IS ALSO KNOWN AS MINIMUM SPANNING TREE

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
//THIS ALGO IS USED TO CONVERT GRAPH INTO A TREE FOR THIS WE FIRST REMOVE ALL 
//ALL THE EDGES AND SORT THEM IN INCREASING ORDER THEN WE KEEP INSERTING EDGES AFTER SORTING
//IF INSERTION OF THAT EDGE DOESNT CREATE A LOOP
//TO CHECK IF PARTICULAR INSERTIONN CREATES A LOOP WE USE DSU BECAUSE IF 2 NODES ARE HAVING 
//SAME ULTIMATE PARENT THEN A NODE BETWEEN WILL CREATE A LOOP

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges;
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    for(int i=1;i<=n;i++)
    make(i);

    sort(edges.begin(),edges.end());
    int totalcost=0;
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
        cout<<u<<" "<<v<<endl;
    }
    cout<<totalcost<<endl;

}