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
    int n;
    cin >> n;
    if (n % 3 == 2)
    {
        fr(i, 1, n)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    else if (n % 3 == 1)
    {
        fr(i, 1, n - 4)
        {
            cout << i << " ";
        }
        cout << n - 2 << " " << n - 3 << " " << n - 1 << " " << n << endl;
    }
    else if (n % 3 == 0)
    {
        for (int i = 1; i <= n - 6; i++)
            cout << i << ' ';
        cout << n - 4 << ' ' << n - 5 << ' ' << n - 2 << ' ' << n - 3 << ' ' << n - 1 << ' ' << n << '\n';
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