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
    vector<int> ans(n + 1);
    if (n == 2)
    {
        ans = {0,2, 1};
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return ;
    }
    else if (n == 3)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n / 2; i++)
    {
        ans[i] = n - i + 1;
    }
    for (int i = n / 2 + 1; i <= n; i++)
    {
        ans[i] = i - n / 2;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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