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

    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) & 1)
    {
        cout << "NO\n";
        return;
    }
    const int x1 = (a + c - b) / 2;
    const int x2 = (a + b - c) / 2;
    const int x3 = (b + c - a) / 2;

    if (x1 < 0 || x2 < 0 || x3 < 0)
    {
        cout << "NO\n";
        return;
    }

    if (x1 + x2 + x3 + 1 > n)
    {
        cout << "NO\n";
        return;
    }

    int cnt = 3;
    int root;
    if (x1 == 0)
    {
        root = 1;
    }
    else if (x2 == 0)
    {
        root = 2;
    }
    else if (x3 == 0)
    {
        root = 3;
    }
    else
    {
        root = ++cnt;
    }

    cout << "YES" << endl;
    if (x1)
    {
        int cur = root;
        for (int i = 1; i < x1; i++)
        {
            std::cout << cur << " " << ++cnt << "\n";
            cur = cnt;
        }
        std::cout << cur << " " << 1 << "\n";
    }
    if (x2)
    {
        int cur = root;
        for (int i = 1; i < x2; i++)
        {
            std::cout << cur << " " << ++cnt << "\n";
            cur = cnt;
        }
        std::cout << cur << " " << 2 << "\n";
    }
    if (x3)
    {
        int cur = root;
        for (int i = 1; i < x3; i++)
        {
            std::cout << cur << " " << ++cnt << "\n";
            cur = cnt;
        }
        std::cout << cur << " " << 3 << "\n";
    }
    while (cnt < n)
    {
        std::cout << 1 << " " << ++cnt << "\n";
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