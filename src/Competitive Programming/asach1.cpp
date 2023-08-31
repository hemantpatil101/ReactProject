#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 0; i <= n; i++)
            v[i] = i;
        // v[1]=0;
        for (int i = 2; i <= n; i++)
        {
            if (v[i] == i)
            {
                for (int j = i; i * j <= n; j++)
                {
                    v[i * j] = i;
                }
            }
        }
        while (n > 1)
        {
            cout << v[n];
            cout << " ";
            n /= v[n];
        }
        cout << endl;
    }
}