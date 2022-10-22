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

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<bool> vis(n, 0);
    cin >> a;
    string ans = "";
    int k = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (k >= a[i])
        {
            vis[i] = 1;
        }
        else if (k < q)
        {
            vis[i] = 1;
            k++;
        }
        else if (k > q)
        {
            break;
        }
    }
    fr(i, 0, n - 1)
    {
        cout<<vis[i];
    }
    cout<<endl;
}
int main()
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