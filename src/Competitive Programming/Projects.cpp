#include <bits/stdc++.h>

using namespace std;
struct project
{
    int st,en,rwd;
};
bool cmp(project &p1,project &p2)
{
    return p1.en < p2.en;
}
int GetBest(vector<int> &end,int i)
{
    auto itt = lower_bound(end.begin(),end.end(),i);
    if(itt==end.begin())
    return 0;
    else
    {
        itt--;
        return 1 + distance(end.begin(),itt);
    }
}
int main()
{
    int n;
    cin>>n;
    int A[n],B[n],C[n];
    for(int i=0;i<n;i++)
    cin>>A[i]>>B[i]>>C[i];
    
    vector<project> v(n+1);
    for(int i=0;i<n;i++)
    {
        v[i+1].st = A[i];
        v[i+1].en = B[i];
        v[i+1].rwd = C[i];
    }
    
    sort(v.begin()+1,v.end(),cmp);
    vector<int> end;
    n = v.size();
    for(int i=1;i<n;i++)
    end.push_back(v[i].en);
    vector<long long> dp(n+1);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        long long op1 = dp[i-1];
        long long op2 = v[i].rwd;
        
        int j = GetBest(end,v[i].st);
        op2 +=dp[j];
        dp[i] = max(op1,op2);
    }
    cout<<dp[n-1];
    return 0;
}
