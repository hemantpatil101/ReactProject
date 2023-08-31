#include <bits/stdc++.h>
#define int long long int
using namespace std;
// /NEXT GREATEST ELEMENT/
// vector<int> NGE(vector<int> v) // v vector is question vector
// {
//     vector<int> nge(v.size()); //----ans vector
//     stack<int> st;
//     for (int i = 0; i < v.size(); i++)
//     {
//         while (!st.empty() && v[i] > v[st.top()])
//         {
//             nge[st.top()] = i;
//             st.pop();
//         }
//         st.push(i);
//     }
//     while (!st.empty())
//     {
//         nge[st.top()] = -1;
//         st.pop();
//     }
//     return nge; // HAS THE INDEX OF ANS;PRINT v[nge[i]]
// }
// /n=number you want the power of,x=power/
// int power(int n, int x)
// {
//     int ans = 1;
//     for (int i = 0; i < x; i++)
//     {
//         ans *= n;
//     }
//     return ans;
// }
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s1 = 0, s2 = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i = i + 2)
            s1 += a[i];
        for (int i = 1; i < n; i = i + 2)
            s2 += a[i];
        if (s1 <= s2)
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    cout <<"1"<<" ";
                }
                else
                    cout << a[i] <<" ";
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2)
                    cout << "1"
                         << " ";
                else
                    cout << a[i] << " ";
            }
            cout << endl;
        }
    }
}