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

int lowbit(int x)
{
    return x & -x;
}

int b[maxn << 1], e[maxn << 1];

int n, m;
inl void addb(int x)
{
    while (x <= n)
    {
        ++b[x];
        x += lowbit(x);
    }
}
inl void adde(int x)
{
    while (x <= n)
    {
        ++e[x];
        x += lowbit(x);
    }
}
inl int sume(int k)
{
    int s = 0;
    while (k > 0)
    {
        s += e[k];
        k -= lowbit(k);
    }
    return s;
}
inl int sumb(int k)
{
    int s = 0;
    while (k > 0)
    {
        s += b[k];
        k -= lowbit(k);
    }
    return s;
}

void solve()
{
    cin >> n >> m;
    while (m--)
    {
        int l, r, q;
        cin >> q >> l >> r;
        if (q == 1)
        {
            addb(l);
            adde(r);
        }
        else
        {
            int k1 = sume(l-1);
            int k2 = sumb(r);
            cout << k2 - k1 << endl;
        }
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