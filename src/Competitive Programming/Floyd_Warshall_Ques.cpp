#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int dist[n+1][n+1]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cin>>dist[i][j];
    }

    vector<int> order(n,0);
    for(int i=0;i<n;i++)
    cin>>order[i];
    reverse(order.begin(),order.end());
    vector<long long> ans;
    for(int k=0;k<n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
               dist[i][j] = min(dist[i][j],dist[i][order[k]] + dist[order[k]][j]);
            }
        }

        long long sum=0;
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<=k;j++)
            sum+=dist[order[i]][order[j]];
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
}