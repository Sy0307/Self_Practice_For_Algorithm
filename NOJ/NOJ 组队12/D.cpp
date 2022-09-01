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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

int n;
int fa[maxn];
int x[maxn], c[maxn];
ll ans = 0;
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
        return;
    fa[fx] = fy;
}
void solve()
{
    cin >> n;
    fr(i, 1, n)
    {
        cin >> x[i];
        fa[i] = i;
    }
    fr(i, 1, n)
    {
        cin >> c[i];
    }
    ans = 0;
    fr(i, 1, n)
    {
        if (find(i) != find(x[i]))
        {
            merge(find(i), find(x[i]));
            continue;
        }
        else
        {
            int now = i;
            int num = c[i];
            while (x[now] != i)
            {
                now = x[now];
                num = min(c[now], num);
            }
            ans += num;
        }
    }
    cout<<ans<<"\n";
}
int main()
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