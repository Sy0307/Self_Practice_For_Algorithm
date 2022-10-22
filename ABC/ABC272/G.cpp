#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
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

vector<int> a;
int n;
bool check(int m)
{
    if (m < 3)
        return false;
    int cnt = 0;
    map<int, int> mp;
    fr(i, 1, n)
    {
        mp[a[i] % m]++;
        int x = mp[a[i] % m];
        if (x > n - x)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    cin >> n;
    a.resize(n + 1);
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    int tmp = 50;
    while (tmp--)
    {
        int x = a[rand() % n + 1];
        int y = a[rand() % n + 1];
        int d = abs(x - y);
        if (d == 0)
        {
            continue;
        }
        fr(i, 1, sqrt(d))
        {
            if (d % i == 0)
            {
                int m = i;
                if (check(m))
                {
                    cout << m << endl;
                    return;
                }
                m = d / i;
                if (check(m))
                {
                    cout << m << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}