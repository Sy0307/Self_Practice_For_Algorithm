#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 5e5 + 10;
const ll mod = 998244353;
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

#define int long long
int n;
int tree[maxn];
int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int val)
{
    while (x <= n)
    {
        tree[x] += val;
        x += lowbit(x);
    }
}
ll query(int a)
{
    ll ans = 0;
    while (a)
    {
        ans = (ans+tree[a])%mod;
        a -= lowbit(a);
    }
    return ans;
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
ll a[maxn], b[maxn],ans[maxn];
void solve()
{
    cin >> n;
    fr(i, 1, n)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int idx = unique(b + 1, b + 1 + n) - b;
    fr(i, 1, n)
    {
        a[i] = lower_bound(b + 1, b + idx, a[i]) - b;
    }

    fr(i, 1, n)
    {
        ans[i] = query(a[i]) * qsm(2, i - 1ll) % mod;
        add(a[i], qsm(qsm(2, i), mod - 2)%mod);
    }

    ll sum = 0 ;
    fr(i,1,n)
    {
        sum = (sum + ans[i]) % mod;
    }
    cout<<sum<<endl;
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