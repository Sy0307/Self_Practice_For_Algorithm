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
ostream &operator<<(ostream &out, vector<ll> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}

ll n;
bool vis[100];
vector<ll> a;
void get(ll x)
{
    for (int i = 0; i <= 60; i++)
    {
        if (x & (1ll << i))
        {
            vis[i] = 1;
        }
    }
}
void dfs(int step, ll now)
{
    if (step == 60)
    {
        a.push_back(now);
        return;
    }
    if (vis[step])
    {
        dfs(step + 1, now | (1ll << step));
    }
    dfs(step + 1, now);
}
void solve()
{
    cin >> n;
    get(n);
    dfs(0, 0);
    sort(a.begin(), a.end());
    for (auto &x : a)
    {
        cout << x << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}