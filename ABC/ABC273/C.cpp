#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
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
    vector<int> a(n + 1);
    set<int> s;
    vector<int> ans;
    fr(i, 1, n)
    {
        cin >> a[i];
        if (!s.count(a[i]))
        {
            ans.push_back(a[i]);
            s.insert(a[i]);
        }
    }
    sort(ans.begin(), ans.end());
    map<int, int> mp;
    int cnt = ans.size();
    fr(i, 1, n)
    {
        auto it = upper_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
        it = cnt - it;
        mp[it]++;
    }
    fr(i, 1, n)
    {
        cout << mp[i - 1] << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}