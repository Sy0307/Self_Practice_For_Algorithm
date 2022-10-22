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

int n;
int a[maxn];
bool check(int fir)
{
    bool f = 0;
    if (a[fir] & 1)
    {
        f = 1;
    }
    for (int i = fir; i <= n; i+=2)
    {
        if ((a[i] & 1) == f)
        {
            continue;
        }
        else
            return false;
    }
    return true;
}
void solve()
{
    cin >> n;
    fr(i, 1, n)
    {
        cin >> a[i];
    }

    if (check(1) && check(2))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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