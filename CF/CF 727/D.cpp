#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    ll l = 0, r = n - 1;
    ll now = 0;
    ll cost = 0;
    while (l <= r)
    {
        ll num = 0;
        if (num < a[l].first - now)
        {
            num = a[l].first - now;
        }

        if (num > a[r].second)
        {
            now += a[r].second;
            cost += a[r--].second * 2;
        }
        else
        {
            now += num;
            cost += 2 * num;
            a[r].second -= num;
            now += a[l].second;
            cost += a[l++].second;
        }
    }
    cout << cost << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}