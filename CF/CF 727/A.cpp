#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve()
{
    ll n, x, t;
    cin >> n >> x >> t;
    if (t / x >= n)
    {
        cout << n * (n - 1) / 2 << endl;
    }
    else
    {
        ll ans = 0;
        ans = (n - t / x) * (t / x);
        ans += (t / x) * (t / x - 1) / 2;
        cout << ans << endl;
    }
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
    return 0;
}