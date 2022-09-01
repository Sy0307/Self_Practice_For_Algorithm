#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxn = 2e5 + 5, INF = 0x3f3f3f3f;
int h[maxn], e[maxn], ne[maxn], idx;
int A[maxn], B[maxn], p[maxn], f[maxn];
ll sum[maxn];

void add(int a, int b, int c, int d)
{
    e[idx] = b, ne[idx] = h[a], A[idx] = c, B[idx] = d, h[a] = idx++;
}
void dfs(int u, ll suma, ll sumb, int depth)
{
    sum[depth] = sumb;
    int l = 0, r = depth;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (sum[mid] <= suma)
            l = mid;
        else
            r = mid - 1;
    }
    f[u] = r;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int x = e[i];
        dfs(x, suma + A[i], sumb + B[i], depth + 1);
    }
}
void solve()
{
    int n;
    cin >> n;
    idx = 0;
    for (int i = 1; i <= n; i++)
    {
        h[i] = -1;
    }
    for (int i = 2; i <= n; i++)
    {
        int a, b;
        cin >> p[i] >> a >> b;
        add(p[i], i, a, b);
    }
    dfs(1, 0, 0, 0);
    for (int i = 2; i <= n; i++)
    {
        cout << f[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}