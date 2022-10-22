#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
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

bool vis[1010];
void init()
{
    fr(i, 2, 1000)
    {
        if (!vis[i])
        {
            for (int j = i; j <= 1000; j += i)
            {
                vis[j] = true;
            }
        }
    }
}
void solve()
{
    init();
    int x;
    cin >> x;
    fr(i, 2, x)
    {
        if (vis[i] && x % i == 0 && vis[x / i])
        {
            cout << i <<" "<<x / i << endl;
            return; 
        }
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