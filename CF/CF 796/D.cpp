#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    if (k < n)
    {
        ll ans = 0;
        for (int i = k; i <= n; i++)
        {
            ans = max(ans, a[i] - a[i - k]);
        }
        cout << ans + (k - 1) * k / 2 << endl;
    }
    else
    {
        ll ans = a[n]+k-n +1LL*(k- n+k)*(n-1)/2;
        cout << ans << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}