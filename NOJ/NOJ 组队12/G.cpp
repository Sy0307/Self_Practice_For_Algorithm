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

ll ans = 0;
ll n, k, p, m;
ll a[maxn], b[maxn], w[maxn], s[maxn], f[maxn];
ll borad[maxn], num[maxn];
void dfs(ll x, ll rest)
{
    while (a[x] == 0 && x)
        x--;
    if (rest == 0 || x == 0)
    {
        ll tot = 0;
        fr(i, 1, k)
        {
            if (borad[i] <= w[m])
                tot += f[borad[i]];
            else
                tot += s[m + 1];
        }
        if (ans < tot)
            ans = tot;
        return;
    }
    fr(i, 1, k) if (num[i] < p)
    {
        a[x]--;
        num[i]++;
        borad[i] += b[x];
        dfs(x, rest - 1);
        borad[i] -= b[x];
        num[i]--;
        a[x]++;
    }
}
void solve()
{
    cin >> n >> k >> p >> m;
    fr(i, 1, n) cin >> a[i];
    fr(i, 1, n) cin >> b[i];
    fr(i, 1, m) cin >> w[i];
    fr(i, 1, m + 1) cin >> s[i];
    fr(i, 1, m)
    {
        fr(j, w[i - 1] + 1, w[i])
        {
            f[j] = s[i];
        }
    }
    ans = 0;
    dfs(n, k * p);
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}