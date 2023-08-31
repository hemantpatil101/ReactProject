#include <iostream>
#include <vector>
using namespace std;

void solve()
{  
    long long int n, d;
    cin >> n >> d;

    vector<int> fre(30002, 0);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        fre[a]++;
    }

    vector<vector<int>> dp(30010, vector<int>(552, -1));
    int ans = 0;

    if (fre[d] > 0)
        dp[d][d] = fre[d];

    for (int i = d + 1; i <= 30000; i++)
    {
        for (int j = 1; j <= 550; j++)
        {
            if (i > j)
                dp[i][j] = max(dp[i][j], dp[i - j][j] + fre[i]);
            if (i > j + 1)
                dp[i][j] = max(dp[i][j], dp[i - j - 1][j + 1] + fre[i]);
            if (i > j - 1)
                dp[i][j] = max(dp[i][j], dp[i - j + 1][j - 1] + fre[i]);
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
