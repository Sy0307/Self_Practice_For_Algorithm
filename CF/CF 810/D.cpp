#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2000000 + 1000;
const int INF = 0x3f3f3f3f;
int n, m, x[MAXN], p[MAXN], d[MAXN], mx, mi;
struct node
{
    int pos, k;
};
bool cmp(node &a, node &b)
{
    if (a.pos != b.pos)
        return a.pos < b.pos;
    return a.k < b.k;
}
void upd(int id, int val)
{
    if (val <= m)
        return;
    mx = max(mx, id + val - m);
    mi = min(mi, id - val + m);
}
void solve()
{
    vector<node> v;
    cin >> n >> m;
    v.push_back({-INF, 0});
    v.push_back({INF, 0});
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> p[i];
        v.push_back({x[i] - p[i] + 1, 1});
        v.push_back({x[i] + 1, -2});
        v.push_back({x[i] + p[i] + 1, 1});
    }
    sort(v.begin(), v.end(), cmp);
    int pre = 0;
    mx = -INF, mi = INF;
    for (int i = 1; i < v.size() - 1; i++)
    {
        d[i] = d[i - 1] + v[i].k;
        if (v[i].pos != v[i + 1].pos)
        {
            upd(v[i].pos, pre + d[i]);
            upd(v[i + 1].pos - 1, pre + d[i] * (v[i + 1].pos - v[i].pos));
        }
        pre += d[i] * (v[i + 1].pos - v[i].pos);
    }
    for (int i = 1; i <= n; i++)
    {
        if ((x[i] + p[i]) >= mx && (x[i] - p[i]) <= mi)
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}