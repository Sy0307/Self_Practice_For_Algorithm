#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
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

string s[2];
int n;
int sum = 0;
int f[maxn][2];

void solve()
{
    cin >> n;
    cin >> s[0] >> s[1];
    s[0] = "0" + s[0];
    s[1] = "0" + s[1];
    fr(i, 1, n)
    {
        sum +=( s[0][i] == '1' )+ (s[1][i] == '1');
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            if (s[j ^ 1][i] == '0')
            {
                f[i][j] += f[i + 1][j];
            }
            else if (s[j][i + 1] == '0')
            {
                f[i][j] = min(f[i + 1][j ^ 1], f[i + 1][j] + 1);
            }
            else if (s[j ^ 1][i + 1] == '0')
            {
                f[i][j] = min(f[i + 2][j ^ 1] + 1, f[i + 2][j] + 1);
            }
            else
            {
                f[i][j] = min(f[i + 2][j ^ 1] + 1, f[i + 2][j] + 2);
            }
        }
    }
    cout << sum - f[0][0] << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}