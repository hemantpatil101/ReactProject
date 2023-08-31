
#include <bits/stdc++.h>

using namespace std;
long long sqrt_rel(long long a)
{
    long long l=0;
    long long r=2000000123;
    while(r>l)
    {
        long long mid = (r + l)/2;
        
        if(mid*mid>a)
        r=mid;
        else
        l=mid+1;
    }
    return l - 1;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       long long a,b;
       cin>>a>>b;
       long long ad = sqrt_rel(a);
       long long ut = sqrt_rel(b);
       
       long long cnt=0;
       if(ad==ut)
       {
           for(int i=0;i<3;i++)
           {
               if(a<=ad*(ad+i) && b>=ad*(ad+i))
               cnt++;
           }
       }
       else
       {
           cnt = abs(ut- ad-1)*3;
           for(int i=0;i<3;i++)
           {
               if(a<=ad*(ad+i) && b>=ad*(ad+i))
               cnt++;
               if(a<=ut*(ut+i) && b>=ut*(ut+i))
               cnt++;
           }
       }
       cout<<cnt<<endl;
   }
   return 0;
}
