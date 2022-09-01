#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

int n,m;
const int maxn = 2e5 + 10;
int a[maxn];
int f[maxn][18];
void init()
{

    for (int j = 0; j < 18; ++j)
    {
        for (int i = 1; i + (1 << j) - 1 <= m; ++i)
        {
            if (!j)
                f[i][j] = a[i];
            else
                f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
    }
}

int query(int l, int r)
{
    int k = __lg(r - l + 1);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

void solve()
{
    cin >> n >> m;
    a[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    init();
    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c, d, k, maxheight;
        cin >> a >> b >> c >> d >> k;
        //    a--; b--; c--; d--;
        if (abs(a - c) % k || abs(b - d) % k)
        {
            cout << "NO" << endl;
            continue;
        }
        maxheight = max(a, c);
        maxheight = (n - maxheight) / k * k + maxheight;
        if (maxheight > query(min(b, d), max(b, d)))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}