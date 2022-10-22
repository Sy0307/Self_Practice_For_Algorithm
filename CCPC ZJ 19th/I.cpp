#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int N = 1e6 + 10;
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

const int P = 13331;
ull h[N], p[N], rv[N];
string str;
int n, q;
string ans[2] = {"Putata", "Budada"};

void init()
{
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    for (int i = n; i >= 1; i--)
    {
        rv[i] = rv[i + 1] * P + str[i];
    }
}

ull get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
ull rev(ull l, ull r)
{
    return (rv[l] - rv[r + 1] * p[r - l + 1]);
}

void solve()
{
    cin >> n >> q;
    cin >> str;
    str = "?" + str;
    init();
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (get(a, b) == rev(a, b))
        {
            cout << ans[1] << endl;
        }
        else if ((b - a) & 1)
        {
            cout << ans[1] << endl;
        }
        else
            cout << ans[0] << endl;
    }
}
signed main()
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