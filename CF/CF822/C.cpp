#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e6 + 10;
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

bool vis[maxn];
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "?" + s;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            vis[i] = true;
        }
        else
            vis[i] = false;
    }
    ll ans = 0;
    // if (s[1] == '0')
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         if (!vis[i])
    //         {
    //             ans++;
    //         }
    //     }
    //     cout << ans << endl;
    //     return;
    // }
    for (int i = 1; i <= n; i++)
    {
        if (s[i]=='0')
        {
            bool f = 1;
            for (int j = i; j <= n && f; j += i)
                if (!vis[j])
                {
                    ans += i;
                    vis[j] = true;
                }
                else if(s[j]=='1')
                    f = 0;
        }
    }
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