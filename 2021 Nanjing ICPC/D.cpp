#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
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
int n;
int tree[maxn];
int a[maxn];
bool vis[maxn];
int lowbit(int x)
{
    return x & -x;
}
void add(int x)
{
    while (x <= n)
    {
        tree[x]++;
        x += lowbit(x);
    }
}
int query(int x)
{
    int ans = 0;
    while (x)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
void solve()
{
    cin >> n;
    memset(tree, 0, sizeof(tree));
    memset(vis, 0, sizeof(vis));
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }

    int sum = 0;
    cout << 0 << " ";
    add(a[1]);
    int maxx = a[1];
    vis[a[1]] = 1;

    int cnt = 0;
    int t = 0;
    fr(i, 2, n)
    {
        if (a[i] == maxx)
        {
            t = 1;
            cnt += t;
        }
        else if (a[i] < maxx)
        {
            sum += query(maxx) - query(a[i]);
            cnt += t;
        }
        else
        {
            sum += 2 + cnt;
            maxx = a[i];
            cnt = 0;
            t = 0;
        }
        cout << sum << " \n"[i == n];
        if (!vis[a[i]])
        {
            add(a[i]);
            vis[a[i]] = 1;
        }
    }
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