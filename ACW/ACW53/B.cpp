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

ll make(string s)
{
    ll ans = 0;
    for (auto c : s)
    {
        ans = ans * 10 + (c - '0');
    }
    return ans;
}
bool check(ll a)
{
    return a % 4 == 0;
}
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    fr(i,0,n-1)
    {
        if((s[i] - '0')%4==0)
        {
            ans++;
        }
    }
    for (int i = 1; i <n;i++)
    {
        ll num=(s[i-1]-'0')*10+(s[i]-'0');

        if (num%4==0)
            ans+=i;
    }
    cout<<ans<<endl;
}
int main()
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