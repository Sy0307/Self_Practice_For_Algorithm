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

map<int, int> mp;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    fr(i, 0, n - 1)
    {
        int t1 = (i - a[i] + 1 + n) % n;
        int t2 = (i - a[i] + n) % n;
        int t3 = (i - a[i] - 1 + n) % n;
        mp[t1]++;
        mp[t2]++;
        mp[t3]++;
    }
    int ans = 0;
    fr(i, 0, n)
    {
        ans = max(ans, mp[i]);
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}