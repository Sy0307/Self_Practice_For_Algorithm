#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2000010;
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

#define int ll
int tr[maxn];
int n;
int lowbit(int x)
{
    return x & -x;
}
int que(int x)
{
    int ans = 0;
    while (x)
    {
        ans += tr[x];
        x -= lowbit(x);
    }
    return ans;
}
void add(int a, int b)
{
    for (int i = a; i <= n; i += lowbit(i))
        tr[i] += b;
}
int a[maxn];
int high[maxn], low[maxn];
void solve()
{
    cin >> n;
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    fr(i, 1, n)
    {
        int y = a[i];
        high[i] = que(n) - que(y);
        low[i] = que(y - 1);
        add(y, 1);
    }
    memset(tr, 0, sizeof tr);

    ll ans1 = 0, ans2 = 0;
    ford(i, n, 1)
    {
        int y = a[i];
        ans1 += que(y - 1) * low[i];
        ans2 += (que(n) - que(y)) * high[i];
        add(y, 1);
    }
    cout << ans2 << " " << ans1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}