#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    pair<ll, ll> as[n + 2];
    for (ll i = 1; i <= n; i++)
    {
        cin >> as[i].first >> as[i].second;
    }
    sort(as + 1, as + n + 1, cmp);
    priority_queue<ll, vector<ll>, greater<ll>> p;
    for (ll i = 1; i <= n; i++)
    {
        if (p.size() < m)
        {
            p.push(as[i].first + as[i].second);
        }
        else
        {
            ll lst = p.top();
            p.pop();
            p.push(max(as[i].first, lst) + as[i].second);
        }
    }
    ll ans = -1;
    while (!p.empty())
    {
        ans = max(ans, p.top());
        p.pop();
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
