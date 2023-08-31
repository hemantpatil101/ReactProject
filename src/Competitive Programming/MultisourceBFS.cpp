#include<bits/stdc++.h>
const int N = 1e5+5;
const int INF = 1e9;
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,m;
    cin>>n>>m;
    int A[n][m];
    int mx=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
            mx = max(mx,A[i][j]);
        }
    }
    queue<pair<int,int>> q;
    vector<vector<int>> level(n,vector<int>(m,0));
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(A[i][j]==mx)
           {
              q.push({i,j});
              vis[i][j]=1;
              level[i][j]=0;
           }   
        }
    }
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
               int nr = x+i;
               int nc = y+j;
               if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc])
                {
                   vis[nr][nc]=1;
                   q.push({nr,nc});
                   level[nr][nc] = level[x][y] + 1;
                }
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        ans = max(ans,level[i][j]);
    }

    cout<<ans<<endl;
    }
    
}