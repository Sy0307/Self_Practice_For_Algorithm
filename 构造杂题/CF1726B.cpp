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
    int n, m;
    cin >> n >> m;
    if (m < n)
    {
        cout << "NO" << endl;
        return;
    }
    else if (m % n == 0)
    {
        cout<<"YES"<<endl;
        fr(i, 1, n)
        {
            cout << m / n << " ";
        }
        cout << "\n";
        return;
    }
    else if ((m & 1) && (n & 1) == 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if ((m & 1) && (n & 1))
    {
        fr(i, 1, n - 1)
        {
            cout << 1 << " ";
        }
        cout << m - (n - 1) << endl;
    }
    else if ((m & 1) == 0 && (n & 1) == 0)
    {
        fr(i, 1, n - 2)
        {
            cout << 1 << " ";
        }
        cout << (m - (n - 2)) / 2 << " ";
        cout << (m - (n - 2)) / 2 << endl;
    }
    else if ((m & 1) == 0 && (n & 1))
    {
        fr(i, 1, n - 1)
        {
            cout << 1 << " ";
        }
        cout << m - (n - 1) << endl;
    }
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