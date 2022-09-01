#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxn = 1001;
const int mod = 1e9 + 7;

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
ll n, a[maxn];
mint m;
ll dp[555][555];
ll dfs(int L, int R)
{
    if ((R - L + 1) % 2)
        return 0;
    if (L > R)
        return 1;
    if (dp[L][R] != -1)
        return dp[L][R];
    mint res = 0;
    if (a[L] == 0)
    {
        for (int i = L + 1; i <= R; i += 2)
        {
            if (a[i] == 0)
            {
                res += m * dfs(i + 1, R) * dfs(L + 1, i - 1);
            }
            else if (a[i] < 0)
            {
                res += dfs(i + 1, R) * dfs(L + 1, i - 1);
            }
        }
    }
    else if (a[L] > 0)
    {
        for (int i = L + 1; i <= R; i += 2)
        {
            if (a[i] == 0)
            {
                res += dfs(i + 1, R) * dfs(L + 1, i - 1);
            }
            else if (a[i] == -a[L])
            {
                res += dfs(i + 1, R) * dfs(L + 1, i - 1);
            }
        }
    }
    return dp[L][R] = res.get();
}
void slove()
{
    cin >> n >> m.x;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << dfs(1, n) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        slove();
    }
    return 0;
}