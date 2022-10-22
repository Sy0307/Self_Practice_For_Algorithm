
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
#define pb push_back
int n, m;
const int N = 2e5 + 10;
int w[N];
int e[N << 1], ne[N << 1], h[N], idx;
bool st[N];
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    set<PII> se;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
        b[x] += w[y];
        b[y] += w[x];
    }
    for (int i = 1; i <= n; i++)
    {
        se.insert({b[i], i});
    }
    int ma = -2e18;
    while (se.size())
    {
        auto t = se.begin();
        int val = (*t).first, id = (*t).second;
        ma = max(ma, val);
        se.erase(t);
        st[id] = true;
        for (int i = h[id]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (st[j])
                continue;
            auto idx = se.find({b[j], j});
            b[j] -= w[id];
            se.erase(idx);
            se.insert({b[j], j});
        }
    }
    cout << ma << endl;
    return 0;
}