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

#define int ll
void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    s = '?' + s;
    vector<bool> vis(n + 1);
    fr(i, 1, n)
    {
        if (s[i] == '1')
        {
            vis[i] = 1;
        }
        else
            vis[i] = 0;
    }
    vector<int> a(n + 1);
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    int ans = 0;
    if (vis[1])
    {
        ans += a[1];
    }
    priority_queue<int> q;
    int cnt = 0 ;
    fr(i, 2, n)
    {
        if (vis[i])
        {
            if (!vis[i - 1])
            {
                q.push(a[i - 1]);
            }
            if (q.size())
            {
                if (q.top() > a[i])
                {
                    ans += q.top();
                    q.pop();
                    q.push(a[i]);
                }
                else
                {
                    ans += a[i];
                }
            }
            else
                ans += a[i];
        }
        else
            while(q.size())
            {
                q.pop();
            }
        //  cout<<ans<<endl;
    }
    cout << ans << endl;
}
signed main()
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