#include<bits/stdc++.h>
const int N = 1e5+5;
const int INF=1e9;
using namespace std;

//SHORTEST PATH BETWEEN ALL PAIRS
//HERE ORDER DOESNT MATTER IN WHICH ORDER YOU ARE PROCESSING K

int main()
{
    int n,m,a,b,c;
    cin>>n>>m;

    int dist[n+5][n+5];
    for(int i=1;i<n+5;i++)
    {
        for(int j=1;j<n+5;j++)
        {
           if(i==j)  
           dist[i][j]=0;
           else
           dist[i][j] = INF;
        }
    }
    for(int i=0;i<m;i++)
    { 
        cin>>a>>b>>c;
        dist[a][b]=c;
    }

        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]==INF)
                cout<<"I ";
                else 
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }*/

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]==INF)
                cout<<"I ";
                else 
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
}