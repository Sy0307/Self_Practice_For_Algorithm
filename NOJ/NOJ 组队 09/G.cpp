#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1000003;
const int mod = 1000000007;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

class str_hash
{
    //从1开始计数
    const static int t1 = 436522843;
    //  const static int t2 = 1019260817;
    const static int maxn = 1e6 + 7;
    ull base = 233;
    ull p1[maxn];
    //  ull p2[maxn];
    char s[maxn];
    unordered_map<ull, ull> rv;
    unordered_map<ull, ull> hs1;
    int n;

public:
    void pre()
    {
        p1[0] = 1;
        for (int i = 1; i <= maxn; i++)
            p1[i] = p1[i - 1] * base % t1;
    }
    void init(string &str)
    {
        n = str.length();
        for (int i = 1; i <= n; i++)
            s[i] = str[i - 1];
        for (int i = 1; i <= n; i++)
        {

            hs1[i] = (hs1[i - 1] * base + s[i]) % t1;
        }
        for (int i = n; i; --i)
            rv[i] = (rv[i + 1] * base + s[i]) % t1;
    }
    ull que(ull l, ull r)
    {
        auto h1 = (hs1[r] - hs1[l - 1] * p1[r - l + 1] % t1 + t1) % t1;
        return h1;
    }
    ull rev(ull l, ull r)
    {
        auto r1 = (rv[l] - rv[r + 1] * p1[r - l + 1] % t1 + t1) % t1;
        return r1;
    }
    // rev(L,R) = que(L,R) 说明是回文
};

string s;
string rever(string &s)
{
    string res;
    for (int i = s.length() - 1; i >= 0; i--)
        res += s[i];
    return res;
}
str_hash h;
void solve()
{
    cin>>s;
    // str_double_hash::init(s);
    int n = s.size();
    int basiclen = -1;
    for (int i = 0; i < n / 2; i++)
    {
        //  cout<<i<<endl;
        if (s[i] == s[n - i - 1])
        {
            basiclen = i + 1;
        }
        else
            break;
    }
    if (s.size() == 1)
    {
        cout << s << endl;
        return;
    }
    string sub = "", rest;
    //   cout<<basiclen<<endl;
    for (int i = 0; i < n; i++)
    {
        if (i >= basiclen && n - i > basiclen)
        {
            sub += s[i];
        }
    }
    if (basiclen >= 1)
        rest = s.substr(0, basiclen);
    else
        rest = "";
    int len1 = 0, len2 = 0;
    // cout<<rest<<endl;
    h.init(sub);
    int k = sub.size();
    for (int i = k; i >= 1; i--)
    {
        //    cout<<i<<endl;
        if (h.que(1, i) == h.rev(1, i))
        {
            len1 = i;
            break;
        }
    }
    len2 = 0;
    for (int i = k - 1; i >= 0; i--)
    {
        if (h.que(k - i, k) == h.rev(k - i, k))
        {
            len2 = i + 1;
            break;
        }
    }
    // cout<<sub<<endl;
    // cout << rest << endl;
    // cout << h.que(5, 9) << endl;
    // cout << h.rev(5, 9) << endl;
    // cout << "len2 = " << len2 << endl;
    if (len1 >= len2)
    {
        cout << rest << sub.substr(0, len1) << rever(rest) << "\n";
    }
    else
    {
        //   cout<<"D"<<endl;
        cout << rest << sub.substr(k - len2, k) << rever(rest) << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    h.pre();
    while (T--)
    {
        solve();
    }
    return 0;
}