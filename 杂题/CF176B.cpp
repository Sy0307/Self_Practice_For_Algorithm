#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define inl inline
#define endl '\n'
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

string a,b;
int ne[maxn], k;
ll f[maxn][2];
void get(string p)
{
    ne[0] = ne[1] = 0;
    int n = p.size() - 1;
    int j = 0;
    fr(i, 2, n)
    {
        while (j && p[i] != p[j + 1])
        {
            j = ne[j];
        }
        if (p[i] == p[j + 1])
        {
            j++;
        }
        ne[i] = j;
    }
}
int kmp(string s, string p)
{
    int n = p.size() - 1;
    int m = s.size() - 1;
    get(p);
    int ans = 0;
    int j = 0;
    fr(i, 1, m)
    {
        while (j && s[i] != p[j + 1])
        {
            j = ne[j];
        }
        if (s[i] == p[j + 1])
        {
            j++;
        }
        if (j == n)
        {
            ans++;
            j = ne[j];
        }
    }
    return ans;
}
void solve()
{
    cin>>a>>b;
    a = "?" + a;
    b = "?" + b;
    cin >> k;
    int n = a.size() - 1;
    int m = b.size() - 1;

    for (int i = n + 1; i <= n * 2; i++)
    {
        a.push_back(a[i - n]);
    }
    a.push_back( '!');
    int p = kmp(a, b);
    if (n != m || !p)
    {
        cout << 0 << endl;
        return;
    }
    bool flag = 0;
    fr(i, 1, n)
    {
        if (a[i] != b[i])
        {
            f[0][1] = 1;
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        f[0][0] = 1;
        p--;
    }

    fr(i, 1, k)
    {
        f[i][0] = (f[i - 1][1] * p % mod + f[i - 1][0] * (p - 1) % mod) % mod;
        f[i][1] = (f[i - 1][1] * (n - p - 1) % mod + f[i - 1][0] * (n - p) % mod) % mod;
    }
    cout << f[k][0] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}