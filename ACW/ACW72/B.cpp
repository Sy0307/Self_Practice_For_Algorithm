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

int n, m;
void solve()
{
    cin >> n >> m;
    vector<int> a(n + 1), b(a);
    priority_queue<int> pq;
    ll tot = 0;
    fr(i, 1, n)
    {
        cin >> a[i] >> b[i];
        tot += a[i];
        pq.push(a[i] - b[i]);
    }
    while (tot > m && pq.size())
    {
        tot -= pq.top();
        pq.pop();
    }
    if (tot > m)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << n - pq.size() << endl;
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