#include<bits/stdc++.h>
using namespace std;
vector<int> nextgreaterele(vector<int> v)
{
   vector<int> ans(v.size());
   stack<int> st;
   st.push(0);
   for(int i=1;i<v.size();i++)
   {
      while(!st.empty() && v[st.top()]<v[i])
      {
         ans[st.top()]=v[i];
         st.pop();
      }
      st.push(i);
   }
   while(!st.empty())
   {
      ans[st.top()]=-1;
      st.pop();
   }
   return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    vector<int> ans=nextgreaterele(v);
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
}