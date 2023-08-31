#include<bits/stdc++.h>
const int M = 1000000007;
using namespace std;
struct DSU {
    vector<int>parent,sizz;
 
    DSU () {}
 
    DSU(int n) {
        for(int i=0;i<=n;i++) parent.push_back(i);
        sizz.assign(n+1,1);
    }
    
    int find_set(int v) {
        if(parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }
 
    void union_set(int u,int v) {
        u = find_set(u);
        v = find_set(v);
 
        if(v == u) return;
 
        if(sizz[u] > sizz[v]) swap(u,v);
        parent[u] = v;
        sizz[v] += sizz[u];
    }
};

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
bool binaryfun(long long x,long long k,vector<vector<long long int>> &v,vector<vector<long long int>> &pf,long long n,long long m)
{
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
         int a = max(1ll,i-x);
         int b = max(1ll,j-x);
         int c= min(n,i+x);
         int d = min(m,j+x);
         long long h = pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1];
         if(v[i-1][j-1]>0 && h>=k+1)
         return true;
      }
   }
   return false;
}
long long binExp(int a,int b)
{
   if(b==0)
   return 1;
   long long g = binExp(a,b/2);
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
   if(b&1)return a*temp*temp;
   else return temp*temp;
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
void solve()
{  
   long long n,m,k,q,x,y;
   long long A[1000],B[1000];
   for(int i=0;i<n;i++)
   cin>>A[i];
   for(int i=0;i<n;i++)
   cin>>B[i];

   for(int i=0;i<n;i++)
   {
     if(A[i]!=B[i])
     {
        cout<<i;
        break;
     }
   }
}  

 
long long v[200001][10];
int main()
{
   ios_base::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);
   
   int t;
   t=1;

   while(t--)
   {
      solve();
   }   
   return 0;
}