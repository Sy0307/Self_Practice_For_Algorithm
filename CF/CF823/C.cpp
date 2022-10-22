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
    string s;
    cin >> s;
    int n = s.size();
    char x = '9';
    array<int, 10> cnt;
    fr(i,0,9) cnt[i] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] <= x)
        {
            cnt[s[i] - '0']++;
            x = s[i];
        }
        else
        {
            cnt[min(9, s[i] - '0' + 1)]++;
        }
    }
    fr(i, 0, 9)
    {
        fr(j,1,cnt[i])
        {
            cout<<i;
        }
    }
    cout << endl;
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