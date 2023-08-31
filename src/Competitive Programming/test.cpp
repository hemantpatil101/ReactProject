#include<bits/stdc++.h>
const int M = 1e9 + 7;
using namespace std;
vector<int> palindrome;
long long inv(long long i) 
{
  return i <= 1 ? i : M - (long long)(M/i) * inv(M % i) % M;
}
 
bool comp(const pair<int,int> &a,const pair<int,int> &b)
{
   return a.first>b.first;
}
 
long long ncr(int n,int r)
{
   long long num=1;
   for(int i=1;i<=n;i++)
   {
      num = ((num % M) * i)%M;
   }
 
   long long den = 1;
   for(int i=1;i<=r;i++)
   den = ((den % M) * i)%M;
   
   
   long long invden = inv(den);
   long long ans = ((num%M)*(invden%M))%M;
   return ans%M;
 
}
long long twodpresum(int a,int b,int c,int d,int n,int m,vector<vector<int>> &v)
{
   vector<vector<int>>pf(n+1,vector<int>(m+1));
   
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
         pf[i][j] = v[i][j] + pf[i-1][j] + pf[i][j-1] + pf[i-1][j-1];
      }
   }
   return pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1];
}
bool binaryfun(long long mid,vector<int> &v)
{
   int cnt=1;
   long long s=v[0];
   for(int i=0;i<v.size();i++)
   {
      if(v[i]-s>2*mid)
      {
         cnt++;
         s=v[i];
      }
   }
   /*cout<<cnt<<endl;*/
   if(cnt<=3)
   return true;
   else
   return false;
   
}
int calc(long long h)
{
    int s=0;
    while(h>0)
    {
        s+=h%10;
        h=h/10;
    } 
    return s;
}
long long binExp(int a,int b)
{
   if(b==0)
   return 1;
   long long g = binExp(a,b/2);
   g%=M;
   if(b&1)
   return (a*(g*g)%M)%M;
   else
   return (g*g)%M;
}
 
long long int n,k,q,a,b,cnt,m,ans=0;
long long rec(string &str,int s,int e,char req)
{
   if(s==e)
   return str[s]!=req;
   int mid = (e+s)/2;
   long long int c1=0,c2=0;
   for(int i=s;i<=mid;i++)
   {
      if(str[i]!=req)
      c1++;
   }
   for(int i=mid+1;i<=e;i++)
   {
      if(str[i]!=req)
      c2++;
   }
   return min(c1+rec(str,mid+1,e,req+1),c2+rec(str,s,mid,req+1));
}
vector<int> primes;
void sieveEratosthenes(long long n)
{
   vector<bool> prime(n+1,1);
   for(int i=2;i*i<=n;i++)
   {
      if(prime[i]==true)
      {
         for(int j=i*i;j<=n;j+=i)
         {
            prime[j]=false;
         }
      }
   }
   for(int i=2;i<=n;i++)
   {
      if(prime[i])
      primes.push_back(i);
   }
}
long long pov(long long a,long long b)
{
   if(b==0) return 1;
   long long temp=pov(a , b/2);
   temp%=M;
   a%=M;
   if(b&1)return ((a*temp*temp)%M);
   else return ((temp*temp)%M);
}
bool isbalanced(string str)
{
   stack<int> st;
   for(int i=0;i<str.size();i++)
   {
      if(str[i]=='(')
      st.push(i);
      else
      {
         if(st.empty())
         return false;
         else
         st.pop();
      }
   }
   if(st.empty())
   return true;
   else
   return false;
}
bool ispalindrome(int a)
{
   vector<int> dig;
   while(a>0)
   {
      dig.push_back(a%10);
      a/=10;
   }
   for(int i=0;i<(dig.size()+1)/2;i++)
   {
      if(dig[i]!=dig[dig.size()-i-1])
      return false;
   }
   return true;
}
void solve()
{  
   long long n,k,q,t1,m;
   cin>>n;
   /*for(int i=0;i<palindrome.size();i++)
   cout<<palindrome[i]<<" ";*/
   
   int A[n];
   unordered_map<int,int> mp;
   for(int i=0;i<n;i++)
   {
      cin>>A[i];
      mp[A[i]]++;
   
   }
   long long ans=0;
   for(auto it:mp)
   {
      /*ans+=(it.second*(it.second+1))/2;*/
      ans+=(it.second*(it.second+1));
      for(int j=0;j<palindrome.size();j++)
      {
         if(mp.find(it.first^palindrome[j])!=mp.end())
         {
            ans+=(it.second*mp[it.first^palindrome[j]]);
         }
      }
   }

   cout<<ans/2<<endl;
   
   
}   


long long v[200001][10];
int main()
{
   ios_base::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);
   
   for(int i=0;i<pov(2,15);i++)
   {
      if(ispalindrome(i))
      palindrome.push_back(i);
   }

   int t;
   cin>>t;
 
   while(t--)
   {
      
      solve();
   }   
   return 0;
}