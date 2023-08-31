#include<bits/stdc++.h>
const int N=1e5+10;
const int INF = 1e9;
using namespace std;



int getx(string s)
{
    return s[0]-'a';
}
int gety(string s)
{
    return s[1]-'1';
}

vector<pair<int,int>> movements = 
{
    {-1,2},{1,2},{-1,-2},{1,-2},
    {2,-1},{2,1},{-2,-1},{-2,1}
};
bool isvalid(int x,int y)
{
    if(x>=0 && x<8 && y<8 && y>=0)
    return true;
    else
    return false;
}
int BFS(string source,string dest,vector<vector<int>>& vis,vector<vector<int>>& level)
{
    int x = getx(source);
    int y = gety(source);
    int desx = getx(dest);
    int desy = gety(dest);
    queue<pair<int,int>> q;

    q.push({x,y});
    level[x][y]=0;
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int a = it.first;
        int b = it.second;

        for(auto it:movements)
        {
            int c = a + it.first;
            int d = b + it.second;
            if(isvalid(c,d) && !vis[c][d])
            {
                q.push({c,d});
                vis[c][d]=1;
                level[c][d] = 1 + level[a][b]; 
                /*cout<<c<<" "<<d<<" "<<level[c][d]<<endl;*/
            }
             
        }
        if(level[desx][desy]!=INF)
        break;
    }
    return level[desx][desy];
}

//QUESTIONS INVOLVING SHORTEST PATH ARE USUALLY IMPLEMENTED USING BFS
//THE REASON FOR THIS BEING THE FACT THAT BFS IS TRAVELLED LEVELWISE
//SO IT GIVES US SHORTEST PATH

    int main()
    {
        int n,m;
        cin>>n;
        string a,b;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            cin>>b;
        
            vector<vector<int>> vis(9,vector<int>(9,0));
            vector<vector<int>> level(9,vector<int>(9,INF));
            cout<<BFS(a,b,vis,level)<<endl;
        }

        



    }