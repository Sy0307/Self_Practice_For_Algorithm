#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxn = 5010;
const int mod = 998244353;
ll c[5010][5010];

template <int T>
struct ModInt
{
    const static int MD = T;
    int x;
    ModInt(ll x = 0) : x(x % MD) {}
    int get() { return x; }
    ModInt operator+(const ModInt &that) const
    {
        int x0 = x + that.x;
        return ModInt(x0 < MD ? x0 : x0 - MD);
    }
    ModInt operator-(const ModInt &that) const
    {
        int x0 = x - that.x;
        return ModInt(x0 < MD ? x0 + MD : x0);
    }
    ModInt operator*(const ModInt &that) const { return ModInt((long long)x * that.x % MD); }
    ModInt operator/(const ModInt &that) const { return *this * that.inverse(); }
    void operator+=(const ModInt &that)
    {
        x += that.x;
        if (x >= MD)
            x -= MD;
    }
    void operator-=(const ModInt &that)
    {
        x -= that.x;
        if (x < 0)
            x += MD;
    }
    void operator*=(const ModInt &that) { x = (long long)x * that.x % MD; }
    void operator/=(const ModInt &that) { *this = *this / that; }
    ModInt inverse() const
    {
        int a = x, b = MD, u = 1, v = 0;
        while (b)
        {
            int t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * v;
            std::swap(u, v);
        }
        if (u < 0)
            u += MD;
        return u;
    }
};
typedef ModInt<mod> mint;

void pre()
{
    for (int i = 0; i <= 5000; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll ans = 0;
    if (k == 0)
    {
        cout << 1 << endl;
        return;
    }
    vector<int> a;
    a.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            a.push_back(i);
    }
    a.push_back(n);
    for (int i = 1; i + k < a.size(); i++)
    {
        int l = a[i - 1] + 1;
        int r = a[i + k] - 1;
        ans = (ans + c[r - l + 1][k] - 1) % mod;

        if (i == 1)
            continue;
        else
        {
            ans -= c[a[i + k - 1] - l][k - 1];
            ans %= mod;
            ans += 1;
            ans %= mod;
        }
        ans %= mod;
    }
    ans = (ans+1+mod)%mod;
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    pre();
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}