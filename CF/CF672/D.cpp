#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int N = 3e5 + 5;
const int mod = 998244353;
int n, k;
ll fac[N];
struct node
{
    int val, idx;
    node()
    {
    }
    node(int x, int y)
    {
        idx = x, val = y;
    }
    bool operator<(const node &A) const
    {
        if (idx == A.idx)
            return val > A.val;
        return idx < A.idx;
    }
} t[N << 1];
ll qsm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll cm(ll x, ll y)
{
    if (x == y)
        return 1;
    return fac[y] * qsm(fac[x], mod - 2) % mod * qsm(fac[y - x], mod - 2) % mod;
}
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

void solve()
{
    int n, k;
    cin >> n >> k;
    fac[0] = fac[1] = 1;
    fr(i, 2, n)
    {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    int cnt = 0;
    fr(i, 1, n)
    {
        int x, y;
        cin >> x >> y;
        t[++cnt] = node(x, 1);
        t[++cnt] = node(y, -1);
    }
    sort(t + 1, t + 1 + cnt);
    ll ans = 0, res = 0;
    fr(i, 1, cnt)
    {
        if (t[i].val == 1)
        {
            res++;
            if (res >= k)
            {
                ans = (ans + cm(k - 1, res - 1)) % mod;
            }
        }
        else
        {
            res--;
        }
    }
    cout<<ans<<endl;
    return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}