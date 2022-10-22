#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

ll n, m;
void solve()
{
    cin >> n >> m;
    vector<ll> a(n + 1, 0);
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    auto pre(a);
    fr(i, 1, n)
    {
        pre[i] += pre[i - 1];
    }
    ll now = 0;
    fr(i, 1, m)
    {
        now += a[i] * i;
    }
    ll ans = now;
    ans = max(ans, now);
    fr(i, 1, n - m)
    {
        //  cout << now << endl;
        now -= pre[i + m-1] - pre[i-1];
        now += a[i+m]*(m);
        ans = max(ans, now);
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}