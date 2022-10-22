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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int kk = k;
    int f[maxn] = {0};
    for (int i = 0; i < n && kk; i++)
    {
        if (k % 2 == s[i] - '0')
        {
            f[i] = 1;
            kk--;
        }
    }
    f[n - 1] += kk;
    fr(i, 0, n - 1)
    {
        if ((k - f[i]) & 1)
        {
            s[i] = '1' - (s[i] - '0');
        }
    }
    cout << s << endl;
    fr(i, 0, n - 1)
    {
        cout << f[i] << " ";
    }
    cout << endl;
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