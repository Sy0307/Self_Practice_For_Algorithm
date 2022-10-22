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

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    int cnt[30][30] = {0};
    fr(i, 1, n)
    {
        int c1 = a[i] - 'a';
        int c2 = b[n - i + 1] - 'a';
        if (c1 > c2)
        {
            swap(c1, c2);
        }
        cnt[c1][c2]++;
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (cnt[i][j] & 1)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    int sum = 0;
    fr(i, 0, 25)
    {
        sum += cnt[i][i] % 2;
    }
    if (sum > n % 2)
    {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
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