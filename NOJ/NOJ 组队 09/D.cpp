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

class str_hash
{

    //从1开始计数
    const static int maxn = 1e5 + 7;
    ull base = 100071; //经验值
    ull p[maxn];
    char s[maxn];
    unordered_map<ull, ull> rv;
    unordered_map<ull, ull> hs;
    int n;

public:
    void init(string &str)
    {
        n = str.length();
        for (int i = 1; i <= n; i++)
            s[i] = str[i - 1];
        p[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            hs[i] = hs[i - 1] * base + s[i];
            p[i] = p[i - 1] * base;
        }
        for (int i = n; i; --i)
            rv[i] = (rv[i + 1] * base + s[i]);
    }
    ull que(ull l, ull r)
    {
        return hs[r] - hs[l - 1] * p[r - l + 1];
    }
    ull rev(ull l, ull r)
    {
        return rv[l] - rv[r + 1] * p[r - l + 1];
    }
    // rev(L,R) = que(L,R) 说明是回文
};
const int mod = 1000000007;
bool match[100010];
ll dp[100010];
ll s1[100005];
ll s2[100005];
void solve()
{
    string str, substr;
    cin >> str >> substr;
    str_hash h1, h2;
    h1.init(str);
    h2.init(substr);
    int l1 = str.size();
    int l2 = substr.size();
    int k2 = h2.que(1, l2);
    for (int i = l2; i <= l1; i++)
    {
        int st = i - l2 + 1;
        int k1 = h1.que(st, i);
        if (k1 == k2)
        {
            match[i] = 1;
        }
    }
    for (int i = 1; i <= l1; i++)
    {
        if (!match[i])
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = ((i - l2 + 1) + s2[i - l2]) % mod;
        }
        s1[i] = (s1[i - 1] + dp[i]) % mod;
        s2[i] = (s2[i - 1] + s1[i]) % mod;
    }
    cout << s1[l1] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}