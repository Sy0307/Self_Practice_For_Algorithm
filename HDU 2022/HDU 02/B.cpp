#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll handle(ll n)
{
    ll ans = LLONG_MAX;
    for (ll i = 0; i * 31 <= n; i++)
    {
        for (ll j = 0; 7 * j + 31 * i <= n; j++)
        {
            if (n == i * 31 + j * 7)
            {
                ans = min(ans, i + j);
            }
        }
    }
    if (ans == LLONG_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}
void solve()
{
    ll n, ans = LLONG_MAX;
    cin >> n;
    if (n > 7 * 31 - 7 - 31)
    {
        ll a = n / 365;
        ll tmp = (n - a * 365);
        ll ans1 = handle(tmp);
        if (ans1 != -1)
        {
            ans = min(ans, a + ans1);
        }
        if (a >= 1)
        {
            a--;
            ll tmp = (n - a * 365);
            ll ans1 = handle(tmp);
            if (ans1 != -1)
            {
                ans = min(ans, a + ans1);
            }
        }
    }
    else
    {
        ll ans1 = handle(n);
        if(ans1 == -1)
        {
            ans = LLONG_MAX;
        }
        else
        {
            ans = min(ans,ans1);
        }
    }
    if (ans == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}