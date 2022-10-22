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

ll x, y, a, b;
void solve()
{
    cin >> x >> y >> a >> b;
    ll g = __gcd(x, y);
    x /= g, y /= g;
    ll tot = x + y;

    if (!(x&1)||!(y&1))
    {
        cout << -1 << endl;
        return;
    }
    if (tot != (tot & -tot))
    {
        cout << -1 << endl;
        return;
    }
    int ans = 0 ; 
    while(tot)
    {
        tot/=2;
        ans++;
    }
    cout<<ans<<endl;
    
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