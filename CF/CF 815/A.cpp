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
pii handle(int a, int b)
{
    pii g;
    g.first = max(a, b);
    g.second = min(a, b);
    return g;
}
void solve()
{
    uint64_t  a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0 && c == 0)
    {
        cout << 0 << endl;
        return;
    }
    else if(a==0||c==0)
    {
        cout<<1<<endl;
        return;
    }
    uint64_t  k1 = a*d;
    uint64_t  k2 = b*c;
    if(k1==k2)
    {
        cout<<0<<endl;
        return;
    }
    if(k1%k2==0||k2%k1==0)
    {
        cout<<1<<endl;
        return;
    }
    cout<<2<<endl;
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