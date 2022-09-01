#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

const int maxn = 1e6 + 10;
const int mod = 1000000007;
const int base = 13331;
ull p[maxn];
ull hs[30][maxn];
void solve()
{
    int n, q;
    cin >> n >> q;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = (p[i - 1] * base) % mod;
    }
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++)
        for (int j = 1; j <= n; j++)
        {
            hs[i][j] = (hs[i][j - 1] * base + ((s[j - 1] - 'a') == i)) % mod;
        }
    while (q--)
    {
        int l, r, len;
        cin >> l >> r >> len;
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < 26; i++)
        {
            a.push_back((hs[i][l + len - 1] - hs[i][l - 1] * p[len] % mod + mod) % mod);
            b.push_back((hs[i][r + len - 1] - hs[i][r - 1] * p[len] % mod + mod) % mod);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool f = 1;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i]&&f)
            {
                cout << "NO" << endl;
                f = 0;
            }
        }
        if (f)
            cout << "YES" << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //  cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}