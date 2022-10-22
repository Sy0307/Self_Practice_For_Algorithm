#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
// const int mod = 1000000007;
#define inl inline
#define endl '\n'
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

#define int ll
int mod;

const ll INF = 1ll << 61;
ll p;
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
ll qsm(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
bool check(int x)
{
    return (qsm(10, x) == 1);
}
void solve()
{
    // cout<<INF<<endl;
    int x, ans = INF;
    cin >> x;
    mod = 9 * x / gcd(ll(13), x);

    int kk = mod;
    p = mod;
    fr(i, 2, sqrt(kk))
    {
        if (kk % i == 0)
        {
            p = p * (i - 1) / i;
        }
        else
            continue;
        while (kk % i == 0)
        {
            kk /= i;
        }
    }
    if (kk != 1)
        p = p * (kk - 1) / kk;
    fr(i, 1, sqrt(p))
    {
        if (i * i == p)
        {
            if (check(i))
            {
                ans = min(ans, i);
            }
        }
        if (p % i == 0)
        {
            if (check(p / i))
            {
                ans = min(ans, p / i);
            }
            if (check(i))
            {
                ans = min(ans, i);
            }
        }
    }
    // cout<<ans<<endl;
    if (ans == INF)
    {
        cout << -1 << endl;
        return;
    }
    cout << --ans << endl;
}
signed main()
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