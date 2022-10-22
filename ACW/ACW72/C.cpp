#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
istream &operator>>(istream &in, vector<int> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
ostream &operator<<(ostream &out, vector<int> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}

bool vis[maxn];
int n;
void solve()
{
    cin >> n;
    vector<int> a(n + 1);
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    ll ans = 1;
    fr(i, 1, n)
    {
        memset(vis, 0, sizeof(vis));
        int j = a[i];
        ll res = 1;
        vis[i] = 1;
        while (!vis[j])
        {
            vis[j] = 1;
            j = a[j];
            res++;
        }
        if (j != i)
        {
            ans = -1;
            break;
        }
        if (!(res & 1))
        {
            res = res / 2;
        }
        ans = ans / __gcd(ans, res) * res;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}