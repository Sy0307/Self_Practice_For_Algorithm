#include <iostream>
#include <cstdio>
using namespace std;

// 并查集 按秩合并 复杂度 O(mlog n)
const int Maxn = 100010;
class DSU_BASIC
{

public:
    int fa[Maxn];
    int siz[Maxn];
    DSU_BASIC(int n)
    {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }
    void init(int n)
    {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }
    int find(int x)
    {
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y)
    {
        int t1 = find(x);
        int t2 = find(y);
        if (t1 != t2)
            fa[t2] = t1;
    }
};

int n, m;
void solve(int cnt)
{
    cin >> n >> m;
    DSU_BASIC dsu(2 * n);
    dsu.init(n * 2);
    bool flag = 1;
    for (int i = 1; i <= m; i++)
    {
        if (!flag)
            continue;
        int x, y;
        cin >> x >> y;
        int fx = dsu.find(x);
        int fxx = dsu.find(x + n);
        int fy = dsu.find(y);
        int fyy = dsu.find(y + n);
        if (dsu.find(fx) == dsu.find(fy) || dsu.find(fxx) == dsu.find(fyy))
        {
            flag = 0;
        }
        dsu.merge(x, y + n);
        dsu.merge(y, x + n);
    }
    cout << "Scenario #" << cnt << ":\n";
    if (!flag)
    {
        cout << "Suspicious bugs found!" << endl;
    }
    else
        cout << "No suspicious bugs found!" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1, x = 0;
    cin >> T;
    while (x < T)
    {
        solve(x + 1);
        x++;
        cout << endl;
    }
    return 0;
}