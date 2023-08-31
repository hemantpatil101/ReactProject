#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>n>>m;
        int A[n+1];
        for(int i=1;i<=n;i++)
        cin>>A[i];

        vector<int> mp[n+1];
        map<int,int> mp1;
        for(int i=0;i<m;i++)
        {
            int ad,ut;
            cin>>ad>>ut;
            mp[ad].push_back(ut);
            mp[ut].push_back(ad);
            
            mp1[ad]++;
            mp1[ut]++;
        }

        int op1=INT_MAX;
        int mx=INT_MAX;
        for(auto it:mp1)
        {
            if(it.second%2)
            {
                mx = min(mx,A[it.first]);
            }
            else
            {
                for(int j=0;j<mp[it.first].size();j++)
                {
                    if(mp1[mp[it.first][j]]%2==0)
                    op1 = min(op1,A[it.first] + A[mp[it.first][j]]);
                }
            }
        }
        
        
       
        if(m%2==0)
        cout<<"0\n";
        else 
        {
            cout<<min(op1,mx)<<endl;
        }
    } 
}