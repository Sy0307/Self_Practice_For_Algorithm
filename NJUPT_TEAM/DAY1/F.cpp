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

int count_zero(unsigned long x)
{
    for (int i = 0; i != 64; ++i)
        if (x >> i & 1)
            return i;
    return 0;
}

int l, r;
void solve()
{
    cin >> l >> r;
    vector<int> a(r - l + 1);
    for (int i = 0; i <= r - l; i++)
    {
        std::cin >> a[i];
    }

    if (l == r)
    {
        std::cout << (a[0] ^ l) << "\n";
        return;
    }
    int k;
    if (l == 0)
    {
        k = 30;
    }
    else
    {
        k = count_zero(l);
    }
    k = min(k, count_zero(r + 1));

    auto make = [&](int x)
    {
        auto t = a;
        for (auto &y : t)
        {
            y ^= x;
        }
        std::sort(t.begin(), t.end());
        if (t[0] == l && t.back() == r)
        {
            std::cout << x << "\n";
            return true;
        }
        return false;
    };

    sort(a.begin(), a.end());
    fr(i, 0, r - l)
    {
        int j = i;
        while (j < r - l + 1 && (a[j] >> (k + 1)) == (a[i] >> (k + 1)))
        {
            j++;
        }
        if (j - i != (2 << k))
        {
            if (make(a[i] ^ l))
            {
                return;
            }
            if (make(a[i] ^ r))
            {
                return;
            }
        }
        i = j - 1;
    }
}
signed main()
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