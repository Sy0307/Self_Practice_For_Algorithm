#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 100;
ll T, a[maxn], d[maxn], n, power, maxstep;
void solve()
{
    int b = 1, p = 0, m = 0;
    cin >> n >> power >> maxstep;
    for (int i = 1; i <= n; i++)
        cin >> a[i], d[i] = a[i];
    d[n + 1] = 0;
    for (int i = n - 1; i >= 1; i--)
        d[i] += d[i + 1];
    int plot;
    while (b && p < n)
    {
        ll y = 0;
        b = 0;
        for (int i = p + 1; i <= min(n, p + maxstep); i++)
        {
            if (i == p + 1 && a[i] <= power)
            {
                power += a[i], p = i;
                b = 1;
                break;
            }
            if (i == p + 1)
                m = a[i], plot = i;
            else if (d[plot + 1] - d[i + 1] + power >= m && a[i] <= power)
            {
                power += d[plot] - d[i + 1] + y, p = i;
                b = 1;
                break;
            }
            else if (m - (d[plot + 1] - d[i + 1]) < a[i])
            {
                y = d[plot] - d[i];
                m = a[i], plot = i;
            }
        }
    }
    if (b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
