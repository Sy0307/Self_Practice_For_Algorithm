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

void solve()
{
    int x1, x2, x3, y1, y2, y3, res = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (y1 == y2 && y3 < y1)
        res = abs(x2 - x1);
    else if (y2 == y3 && y1 < y2)
        res = abs(x2 - x3);
    else if (y1 == y3 && y2 < y1)
        res = abs(x1 - x3);

    cout << res << '\n';

    return;
}
int main()
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