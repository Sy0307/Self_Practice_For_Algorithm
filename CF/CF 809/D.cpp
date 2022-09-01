#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 1e5 + 10;
int a[maxn], mav[maxn];

void solve()
{
    int n, q;
    cin >> n >> q;
    memset(mav, 0, sizeof(mav));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int x = INT_MAX;
        for (int l = 1, r; l <= min(a[i], q); l = r + 1)
        {
            int tmp = a[i] / l;
            r = a[i] / tmp;
            mav[tmp + 1] = max(mav[tmp + 1], x);
            x = tmp;
        }
        mav[0] = max(mav[0], x);
    }
    int ans = INT_MAX;
    int mval = 0;
    for (int i = 0; i <= a[1]; i++)
    {
        mval = max(mav[i], mval);
        ans = min(ans, mval - i);
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}