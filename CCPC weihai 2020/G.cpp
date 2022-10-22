#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll maxn = 5e5 + 10;
const ll base = 137;
const ll mod = 1000000007;
#define inl inline
#define endl '\n'
#define fr(u, a, b) for (int u = a; u <= b; u++)
#define ford(u, a, b) for (int u = a; u >= b; u--)
#define forall(u, a) for (auto &u : a)
istream &operator>>(istream &in, vector<int> &v)
{
    for (auto &u : v)
        in >> u;
    return in;
}
ostream &operator<<(ostream &out, vector<int> &v)
{
    for (auto &u : v)
        out << u << " ";
    return out;
}

//#define int ll
int a[maxn];
int p1[maxn], p2[maxn];
int n, q;
struct node
{
    int l, r, mx, ha, k;
    // 最大值 哈希值 标记
} tr[maxn * 4];
void hash_init()
{
    p1[0] = 1;
    fr(u, 1, n + 10)
    {
        p1[u] = (1ll * p1[u - 1] * base) % mod;
    }
    p2[1] = 1;
    fr(u, 1, n + 10)
    {
        p2[u] = (1ll * p2[u - 1] * base + 1) % mod;
    }
}

void build(int u, int l, int r)
{
    tr[u].l = l;
    tr[u].r = r;
    tr[u].k = 0;
    if (l == r)
    {
        tr[u].mx = a[l];
        tr[u].ha = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    tr[u].mx = max(tr[u * 2].mx, tr[u * 2 + 1].mx);
    tr[u].ha = (1ll * tr[u * 2].ha * p1[tr[u * 2 + 1].r - tr[u * 2 + 1].l + 1] % mod + tr[u * 2 + 1].ha) % mod;
}

void push_down(int u)
{
    tr[u * 2].mx += tr[u].k;
    tr[u * 2].ha = (1ll * tr[u * 2].ha + 1ll * p2[tr[u * 2].r - tr[u * 2].l + 1] * tr[u].k % mod) % mod;
    tr[u * 2 + 1].mx += tr[u].k;
    tr[u * 2 + 1].ha = (1ll * tr[u * 2 + 1].ha + 1ll * p2[tr[u * 2 + 1].r - tr[u * 2 + 1].l + 1] * tr[u].k % mod) % mod;
    tr[u * 2].k += tr[u].k;
    tr[u * 2 + 1].k += tr[u].k;
    tr[u].k = 0;
}

void update(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].mx++;
        tr[u].k++;
        tr[u].ha = (1ll * tr[u].ha + p2[tr[u].r - tr[u].l + 1]) % mod;
        return;
    }
    push_down(u);
    if (tr[u * 2].r >= l)
        update(u * 2, l, r);
    if (tr[u * 2 + 1].l <= r)
        update(u * 2 + 1, l, r);
    tr[u].mx = max(tr[u * 2].mx, tr[u * 2 + 1].mx);
    //
    tr[u].ha = (1ll * tr[u * 2].ha * p1[tr[u * 2 + 1].r - tr[u * 2 + 1].l + 1] % mod + tr[u * 2 + 1].ha) % mod;
}

int query(int u, int l, int r)
{

    if (tr[u].l >= l && tr[u].r <= r)
    {
        return tr[u].ha;
    }
    push_down(u);
    int s = 0;
    if (tr[u * 2].r >= l)
        s += query(u * 2, l, r);
    if (tr[u * 2 + 1].l <= r)
        s = (1ll * s * p1[max(0, min(r, tr[u * 2 + 1].r) - tr[u * 2 + 1].l + 1)] % mod + query(u * 2 + 1, l, r)) % mod;
    return s;
    // if (tr[u].l >= l && tr[u].r <= r)
    //     return tr[u].ha;
    // push_down(u);
    // int ans = 0;
    // if (tr[u * 2].r >= l)
    // {
    //     ans = query(u * 2, l, r);
    // }
    // if (tr[u * 2 + 1].l <= r)
    // {
    //     ans = (1ll * ans * p1[max(0, min(r, tr[u * 2 + 1].r) - tr[u * 2 + 1].l + 1)] % mod + query(u * 2 + 1, l, r)) % mod;
    // }
    // return ans;
}

void avoid_over(int u)
{
    if (tr[u].l == tr[u].r)
    {
        tr[u].mx %= 65536;
        tr[u].ha = tr[u].mx;
        return;
    }
    push_down(u);
    if (tr[u * 2].mx >= 65536)
    {
        avoid_over(u * 2);
    }
    if (tr[u * 2 + 1].mx >= 65536)
    {
        avoid_over(u * 2 + 1);
    }
    tr[u].mx = max(tr[u * 2].mx, tr[u * 2 + 1].mx);
    tr[u].ha = (1ll * tr[u * 2].ha * p1[tr[u * 2 + 1].r - tr[u * 2 + 1].l + 1] % mod + tr[u * 2 + 1].ha) % mod;
}
void solve()
{
    cin >> n >> q;
    // cout<<n<<" "<<q<<endl;
    hash_init();
    fr(u, 1, n)
    {
        cin >> a[u];
    }
    build(1, 1, n);
    while (q--)
    {
        // cout<<q<<endl;
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            update(1, l, r);
            avoid_over(1);
        }
        else
        {
            int x, y, len;
            cin >> x >> y >> len;
            if (query(1, x, x + len - 1) == query(1, y, y + len - 1))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}