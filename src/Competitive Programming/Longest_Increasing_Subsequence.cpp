#include<bits/stdc++.h>
using namespace std;

int Best_Cand(map<int,int> &mp,int ad)
{
    auto it = mp.lower_bound(ad);
    if(it==mp.begin())
    return 0;
    it--;
    return it->second; 
}

void insert(map<int,int> &mp,int ad,int ut)
{
    if(mp[ad]>=ut)
    return;
    mp[ad] = ut;
    auto it = mp.find(ad);
    it++;

    while(it!=mp.end() && it->second <=ut)
    {
        auto temp = it;
        it++;
        mp.erase(temp);
    }
}

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];

    int dp[n] = {0};
    dp[0]=1;
    
    
    map<int,int> mp;
    mp[A[0]] = 1;

    for(int i=1;i<n;i++)
    {
        dp[i] = 1 + Best_Cand(mp,A[i]);
        insert(mp,A[i],dp[i]);
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(ans<dp[i])
        ans  = dp[i];
    }
    cout<<ans;
}