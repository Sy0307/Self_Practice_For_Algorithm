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

int a[4], b[4];
void solve()
{
    int A, B;
    cin >> A >> B;
    if (A == 1)
    {
        a[1]++;
    }
    else if (A == 2)
    {
        a[2]++;
    }
    else if (A == 3)
    {
        a[1]++;
        a[2]++;
    }
    else if (A == 4)
    {
        a[3]++;
    }
    else if (A == 5)
    {
        a[1]++;
        a[3]++;
    }
    else if (A == 6)
    {
        a[2]++;
        a[3]++;
    }
    else if (A == 7)
    {
        a[1]++;
        a[2]++;
        a[3]++;
    }

    if (B == 1)
    {
        b[1]++;
    }
    else if (B == 2)
    {
        b[2]++;
    }
    else if (B == 3)
    {
        b[1]++;
        b[2]++;
    }
    else if (B == 4)
    {
        b[3]++;
    }
    else if (B == 5)
    {
        b[1]++;
        b[3]++;
    }
    else if (B == 6)
    {
        b[2]++;
        b[3]++;
    }
    else if (B == 7)
    {
        b[1]++;
        b[2]++;
        b[3]++;
    }

    int ans = 0;
    // cout<<a[1]<<b[1]<<endl;
    if (a[1] || b[1])
    {
        ans++;
    }
    if (a[2] ||b[2] )
    {
        ans += 2;
    }
    if (a[3] || b[3])
    {
        ans += 4;
    }
    cout << ans << endl;
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