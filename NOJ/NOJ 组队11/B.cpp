#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef priority_queue<int> PQ;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 998244353;
int rnd(int x) { return mrand() % x; }
ll powmod(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// head

int x[2010], y[2010], r[2010];
VI a;
bool f[2010], fg;
int n, l, w;
void fun(int xx, int yy, int rr)
{
    if (xx - rr <= 0 || yy + rr >= w)
    {
        fg = 1;
        return;
    }
    if (fg)
        return;
    rep(i, 0, n)
    {
        if (f[i])
            continue;
        if ((ll)(x[i] - xx) * (ll)(x[i] - xx) + (ll)(y[i] - yy) + (ll)(y[i] - yy) <= (ll)(r[i] + rr) * (ll)(r[i] + rr))
        {
            f[i] = 1;
            fun(x[i], y[i], r[i]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l >> w;
    rep(i, 0, n)
    {
        cin >> x[i] >> y[i] >> r[i];
        if (x[i] + r[i] >= l || y[i] - r[i] <= 0)
        {
            a.pb(i);
            f[i] = 1;
        }
    }
    for (int i : a)
    {
        fun(x[i], y[i], r[i]);
    }
    if (fg)
        cout << "We need backup!";
    else
        cout << "Time to do this!";
}
