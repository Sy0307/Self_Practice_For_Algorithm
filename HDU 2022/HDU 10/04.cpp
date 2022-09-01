#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

int n, m;
int fa[maxn];
double a[maxn], siz[maxn], tot[maxn];
void init()
{
    for (int i = 1; i <=n; i++)
        fa[i] = i, siz[i] = 1;
}
int find(int x)
{

    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void solve()
{
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tot[i] = a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        auto fx = find(x);
        auto fy = find(y);
        fa[fy] = fx;
        siz[fx] += siz[fy];
        tot[fx] += tot[fy];
    }

    for (int i = 1; i <= n; i++)
    {
        auto fx = find(i);
        printf("%.6lf\n",tot[fx]/siz[fx]);
    }
}
int main()
{
    
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}