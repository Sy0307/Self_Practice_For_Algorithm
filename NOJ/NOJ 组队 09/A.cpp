#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull; //自然溢出
const int maxn = 1000010;
int ans[maxn];

namespace str_hash
{
    //从1开始计数
    const static int t1 =  998244353;
    const static int t2 =  1019260817;
    const int maxn = 2e6 + 7;
    ull base = 131; //经验值
    ull p1[maxn];
    ull p2[maxn];
    char s[maxn];
    unordered_map<ull, ull> rv;
    unordered_map<ull, ull> hs1;
    unordered_map<ull, ull> hs2;
    int n;
    void init(string &str)
    {
        n = str.length();
        for (int i = 1; i <= n; i++)
            s[i] = str[i - 1];
        p1[0] = 1;
        p2[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            p1[i] = p1[i - 1] * base % t1;
            p2[i] = p2[i - 1] * base % t2;
            hs1[i] = (hs1[i - 1] * base + s[i]) % t1;
            hs2[i] = (hs2[i - 1] * base + s[i]) % t2;
        }
        for (int i = n; i; --i)
            rv[i] = (rv[i + 1] * base + s[i]);
    }
    ull que(ull l, ull r)
    {
        auto h1 = (hs1[r] - hs1[l - 1] * p1[r - l + 1] % t1 + t1) % t1;
        auto h2 = (hs2[r] - hs2[l - 1] * p2[r - l + 1] % t2 + t2) % t2;
        return h1 * t2 + h2;
    }
    ull rev(ull l, ull r)
    {
        auto r1 = (rv[l] - rv[r + 1] * p1[r - l + 1] + t1) % t1;
        auto r2 = (rv[l] - rv[r + 1] * p2[r - l + 1] + t2) % t2;
        return r1 * t2 + r2;
    }
    // rev(L,R) = que(L,R) 说明是回文
}

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    //   cout << 1 << endl;
    str_hash::init(s);
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n / 2; i++)
    {
        //    cout << i << endl;
        int l = 1, r = i + 1, mid;
        while (l < r)
        {
            mid = (l + r) >> 1;
            if (str_hash::que(i - mid + 1, i + mid - 1) == str_hash::que(n - i + 1 - mid + 1, n - i + 1 + mid - 1))
            {
                l = mid + 1;
            }
            else
                r = mid;
        }
        l--;
        ans[i - l + 1] = max(ans[i - l + 1], 2 * l - 1);
    }
    for (int i = 1; i <= n / 2; i++)
    {
        ans[i] = max(ans[i], ans[i - 1] - 2);
        cout << ans[i] << " ";
    }
    if (n & 1)
        cout << -1 << endl;
    else
        cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    // string s = "abab";
    // str_hash::init(s);
    // // cout<<(str_hash::que(1,4)==str_hash::rev(1,4))<<endl;
}