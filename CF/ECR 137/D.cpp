#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define endl '\n'
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
istream &operator>>(istream &in, vector<int> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
ostream &operator<<(ostream &out, vector<int> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    // reverse(s.begin(), s.end());
    while (s.begin() != s.end() && *s.begin() == '0')
    {
        s.erase(s.begin());
    }
    if (s.empty())
    {
        cout << 0 << endl;
        return;
    }
    if (s.find('0') == string::npos)
    {
        cout << s << endl;
        return;
    }
    int b = s.find('0');
    auto ans = s;
    fr(i, 0, b)
    {
        auto tmp = s;
        for (int j = 0; j + i < s.size(); j++)
        {
            tmp[j+i]|=s[j];
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
signed main()
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