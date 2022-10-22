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

const int N = 12, M = 100;

int c[1 << N], w[N];
char t[N + 2];
int f[1 << N][M + 2];
int n, m, q;
void solve()
{
    cin >> n >> m >> q;
    fr(i, 0, n - 1)
    {
        cin >> w[i];
    }
    fr(i, 0, m - 1)
    {
        cin >> t;
        int k = 0;
        fr(j, 0, n - 1)
        {
            k |= (t[j] - '0') << j;
        }
        c[k]++;
    }

    fr(t, 0, (1 << n) - 1)
    {
        if (!c[t])
            continue;
        fr(k, 0, (1 << n) - 1)
        {
            int ans = 0;
            int h = t ^ k;
            fr(j, 0, n - 1)
            {
                if ((h >> j & 1) == 0)
                {
                    ans += w[j];
                }
            }
            if (ans <= 100)
            {
                f[k][ans] += c[t];
            }
        }
    }

    for (int t = 0; t < 1 << n; t++)
    {
        for (int i = 1; i <= 100; i++)
            f[t][i] += f[t][i - 1];
    }
    while (q--)
    {
        int k;
        cin >> t >> k;
        int w = 0;
        for (int j = 0; j < n; j++)
        {
            w |= (t[j] - '0') << j;
        }
        cout << f[w][k] << "\n";
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