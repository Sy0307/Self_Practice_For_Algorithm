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
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    int x;
    cin >> x;
    string ans(n, '1');
    ans = " " + ans;
    fr(i, 1, n)
    {
        if (s[i] == '0')
        {
            if (i - x >= 1)
            {
                ans[i - x] = '0';
            }
            if (i + x <= n)
            {
                ans[i + x] = '0';
            }
        }
    }

    // cout<<ans<<"kk"<<endl;

    for (int i = 1; i <= n; i++)
    {
        int tot = 0;
        if (i - x >= 1 && ans[i - x] == '1')
        {
            tot++;
        }
        if (i + x <= n && ans[i + x] == '1')
        {
            tot++;
        }
        if (!tot && s[i] == '1')
        {
            // cout << ans << endl;
            // cout << i << endl;
            cout << -1 << endl;
            return;
        }
        if (tot >= 1 && s[i] == '0')
        {
            // cout << ans << endl;
            // cout << i << endl;
            cout << -1 << endl;
            return;
        }
    }
    ans = ans.substr(1, n);
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}