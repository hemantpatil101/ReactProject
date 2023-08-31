#include<bits/stdc++.h>
using namespace std;

vector<int> parent,siz;
void make(int n)
{
    for(int i=0;i<n;i++)
    {
        parent.push_back(i);
        siz.push_back(1);
    }
}
int find(int v)
{
    if(v==parent[v])
    return v;
    return parent[v] = find(parent[v]);
}
void Union(int a,int b)
{
    a=find(a);
    b=find(b);  
    if(a!=b)
    {
        if(siz[a]<siz[b])
        swap(a,b);
        parent[b]=a;
        siz[a]+=siz[b];
    }
}
int main()
{
   
}