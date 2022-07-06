#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 2), dp(n + 10, 0);
    vector<vector<bool>> f(n + 2, vector<bool>(n + 2, 1));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        vector<int> b(n + 1, 0);
        int cnt = 0;
        for (int j = i; j <= n; j++)
        {
            b[a[j]]++;
            cnt = max(cnt, b[a[j]]);
            if ((j - i + 1) & 1)
                f[i][j] = 0;
            else
                f[i][j] = (cnt <= (j - i + 1) / 2);
        }
    }
    for (int i = 1; i <= n; i++)
        if (f[1][i - 1]) //
        {
            dp[i] = 1;
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] == a[j] && dp[j] && f[j + 1][i - 1])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (f[i + 1][n])
        {
            ans = max(ans, dp[i]);
        }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}