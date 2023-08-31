#include<bits/stdc++.h>
const int N=505;
const int M=1e9+7;
using namespace std;


/*long long helper(int i,int j,long long A[])
{
    if(i>j)return 0;
    if(i==j) return A[j];

    if(dp[i][j]!=-1) return dp[i][j];
    
    long long int a1 = A[i]+ min(helper(i+2,j,A),helper(i+1,j-1,A));
    long long int a2 = A[j] + min(helper(i+1,j-1,A),helper(i,j-2,A));
    return dp[i][j] = max(a1,a2);
}*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,x;
       cin>>n;
       vector<int> A(n);

       for(int i=0;i<n;i++)cin>>A[i];

       stack<int> st;
       
       int i=0,j=n-1;

       long long ans=0;
       while(i<j)
       {
        int temp=i;
          vector<int> v1={i};
          if(find_end(A.begin()+temp+1,A.begin() + j+1,v1.begin(),v1.end())!=A.end())
          temp = find_end(A.begin()+temp+1,A.begin() + j+1,v1.begin(),v1.end()) - A.end();
          
          int d2=j;
          if(find(A.begin()+i,A.begin() + j,A[j])!=A.end())
          {
            d2 = (find(A.begin()+i,A.begin() + j,A[j]) - A.begin());
          }
          if(temp==i || d2==j)
          {
            if(temp==i)
            i++;
            else if(d2==j)
            j--;
          }
          else if(temp==d2)
          {
            ans+=(j-i+1);
          }  
          else if(temp<d2)
          {
            ans+=(temp-i+1);
            ans+=(j-d2+1);
            i=temp+1;
            j=d2-1;
          }
          else if((temp-i)<(j-d2))
          {
            ans+=(j-d2+1);
             j=d2-1;
          }
          else
          {
            ans+=(temp-i+1);
            i=temp+1;
          }
       }
       cout<<ans<<endl;
       


    }
}