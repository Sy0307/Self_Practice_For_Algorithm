#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

using ll = long long;
int n, m;
ll rec[100];
bool vis[maxn], ust[maxn *20 + 10] = {0};
void solve()
{
    cin >> n >> m;
    ll ans = 1;
    ll tot = 0;
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!ust[i * j])
            {
                tot++;
            }
            ust[i * j] = 1;
        }
        rec[i] = tot;
    }
    for (ll i = 2; i <= n; i++)
    {
        ll j;
        if (vis[i])
            continue;
        for (j = 1; pow(i, j) <= n; j++)
        {
            vis[(ll)pow(i, j)] = 1;
        }
        ans += rec[j - 1];
    }
    cout << ans << endl;
}
int main()
{
    solve();
}