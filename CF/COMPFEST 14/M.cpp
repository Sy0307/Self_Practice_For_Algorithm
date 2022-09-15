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

    vector<array<int, 2>> edge1[n], edge2[n];

    fr(i, 1, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edge1[a].push_back({b, c});
        edge2[b].push_back({a, c});
    }

    vector<ll> f(n, -1);
    std::priority_queue<std::pair<ll, int>,
                        std::vector<std::pair<ll, int>>,
                        std::greater<>>
        pq;
    pq.push({0, 0});
    while (pq.size())
    {
        auto [d, x] = pq.top();
        pq.pop();

        if (f[x] != -1)
        {
            continue;
        }

        f[x] = d;
        for (auto [y, v] : edge1[x])
        {
            pq.push({d + v, y});
        }
    }

    fr(i, 0, n - 1)
    {
        if (f[i] != -1)
        {
            pq.push({f[i], i});
        }
    }

    fr(i, 0, n - 1)
    {
        f[i] = -1;
    }

    while (pq.size())
    {
        auto [d, x] = pq.top();
        pq.pop();

        if (f[x] != -1)
        {
            continue;
        }

        f[x] = d;
        for (auto [y, v] : edge2[x])
        {
            pq.push({d + v, y});
        }
    }

    fr(i, 1, n - 1)
    {
        cout << f[i] << " \n"[i == n - 1];
    }
    return;
}
int main()
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