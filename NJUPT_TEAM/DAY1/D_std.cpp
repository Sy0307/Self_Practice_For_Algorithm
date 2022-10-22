#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define int long long
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int inf = 1ll << 60;
int phi, m;
int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}
int Ti(int a, int b, int p)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
            if (res > p)
                res %= p;
        }
        a *= a;
        if (a > p)
            a %= p;
        b >>= 1;
    }
    return res;
}
bool ok(int x)
{
    return Ti(10, x, m) == 1;
}
inline void _()
{
    int x, k = inf;
    cin >> x;
    m = 9 * x / gcd(13, x);
    int n = m;
    phi = m;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            phi = phi * (i - 1) / i;
        else
            continue;
        while (n % i == 0)
            n /= i;
    }
    if (n != 1)
        phi = phi * (n - 1) / n;
    // cout << phi << '\n';
    for (int i = 1; i * i <= phi; ++i)
    {
        if (i * i == phi)
        {
            if (ok(i))
                k = min(k, i);
        }
        if (phi % i == 0)
        {
            if (ok(i))
                k = min(k, i);
            if (ok(phi / i))
                k = min(k, phi / i);
        }
    }
    if (k == inf)
        k = -1;
    else
        k--;
    cout << k;
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        _();
    return 0;
}