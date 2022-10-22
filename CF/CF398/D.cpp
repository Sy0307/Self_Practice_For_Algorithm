#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e7 + 10;
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
vector<pii> market;
int home[maxn];

void solve()
{
    int n, m, k;
    int most;
    cin >> n >> m >> k;
    market.resize(m + 1);
    fr(i, 1, n)
    {
        int t;
        cin >> t;
        most = max(most, t);
        home[t]++;
    }
    fr(i, 1, m)
    {
        cin >> market[i].first;
        market[i].second = i;
        most = max(most, market[i].first);
    }
    sort(market.begin() + 1, market.end());
    vector<int> spare(most + 1);
    for (int i = most; i >= 0; i--)
    {
        if (home[i] <= k)
        {
            spare[i] = k - home[i];
        }
        else
        {
            if (i == 0)
            {
                cout << -1 << endl;
                return;
            }
            home[i - 1] += home[i] - k;
        }
    }
    int now = 1;
    int q = 0;
    vector<int> ans;
    fr(i, 0, most)
    {
        if (spare[i])
        {
            while (market[now].first<i && now <= m)
            {
                now++;
            }
            while (spare[i] && now <= m)
            {
                ans.push_back(market[now].second);
                spare[i]--;
                now++;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto i:ans)
    {
        cout << i << " ";
    }
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