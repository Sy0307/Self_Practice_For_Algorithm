#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define NO                    \
    {                         \
        cout << "NO" << endl; \
        return;               \
    }
#define YES                    \
    {                          \
        cout << "YES" << endl; \
        return;                \
    }
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

map<char, int> mp;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    mp.clear();
    if (n != 5)
    {
        NO
    }
    for(auto &c:s)
    {
        mp[c]++;
    }
    if (mp['T'] != 1)
        NO;
    if (mp['i'] != 1)
        NO;
    if (mp['m'] != 1)
        NO;
    if (mp['u'] != 1)
        NO;
    if (mp['r'] != 1)
        NO;
    YES;
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