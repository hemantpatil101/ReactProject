#include<bits/stdc++.h>
using namespace std;
const long long M = 1e18 + 7;
// USED WHEN A AND M ARE OF ORDER 1e18;
long long BinMul(long long a,long long b)
{
    long long ans=0;
    while(b>0)
    {
        if(b&1)
        ans=(ans + a)%M;
        a=(a+a)%M;
        b>>=1;
    }
    return ans;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    cout<<BinMul(a,b);

}