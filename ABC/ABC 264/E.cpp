#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e6 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

int fa[maxn], cnt[maxn];
int query[maxn];
pii g[maxn];
bool vis[maxn];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        fa[i] = i, cnt[i] = 1;
    fr(i, n+1, n + m) fa[i] = 0;
    fr(i, 1, k)
    {
        cin >> g[i].first >> g[i].second;
    }
    int q;
    cin >> q;

    fr(i, 1, q)
    {
        int x;
        cin >> x;
        vis[x] = 1;
        query[i] = x;
    }
    fr(i, 1, k)
    {
        int a = g[i].first, b = g[i].second;
        if (!vis[i])
        {
            a = find(a), b = find(b);
            if (a != b)
            {
                if (a == 0)
                    swap(a, b);
                fa[a] = b;
                cnt[b] += cnt[a];
            }
        }
    }
    vector<int> ans;
    ford(i, q, 1)
    {
        int x = query[i];
        int a = g[x].first, b = g[x].second;
        ans.push_back(cnt[0]);
        a = find(a), b = find(b);
        if (a != b)
        {
            if (a == 0)
                swap(a, b);
            fa[a] = b;
            cnt[b] += cnt[a];
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}