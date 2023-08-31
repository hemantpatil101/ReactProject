#include<bits/stdc++.h>
const int N=1e6+1;
const long long INF=1e18;
using namespace std;

vector<long long> dp(N,INF);

int main()
{
    long long n;
    cin>>n;

    for(int i=0;i<10;i++)dp[i]=1;
    dp[0]=0;
    for(int i=0;i<=n;i++)
    {
        int temp = i;
        vector<int> v;
        while(temp>0)
        {
            v.push_back(temp%10);
            temp/=10;
        }
        for(auto it:v)
        {
           dp[i] = min(dp[i],1+dp[i-it]);
        }
    }
    cout<<dp[n]<<endl;
    
}