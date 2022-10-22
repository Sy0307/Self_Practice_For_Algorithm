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
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
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
    vector<string> a(n);
    cin >> a;
    int res = 0;
    bool f = 1;
    fr(i, 0, n - 1)
    {
        fr(j, 0, m-1)
        {
            if (a[i][j] == '0')
            {
                res++;
            }
            if (i && j && f)
            {
                int cnt = 0;
                if (a[i - 1][j - 1] == '0')
                    cnt++;
                if (a[i - 1][j] == '0')
                    cnt++;
                if (a[i][j - 1] == '0')
                    cnt++;
                if (a[i][j] == '0')
                    cnt++;
                if (cnt >= 2)
                    f = 0;
            }
        }
    }
    if (res <= 1)
    {
        cout << n * m - 2 << endl;
    }
    else
    {
        cout << n * m - res - f << endl;
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