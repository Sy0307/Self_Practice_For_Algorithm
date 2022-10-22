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

int b[maxn];
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    ll ans = 0;
    int cnt = 0;
    fr(i, 1, n)
    {
        cin >> a[i];
        if (a[i] & 1)
        {
            b[++cnt] = a[i];
        }
        else
        {
            ans = max(ans, ans + a[i]);
        }
    }
    sort(b + 1, b + cnt + 1, greater<int>());
    ans+=b[1];
    for (int i = 2; i+1 <= cnt; i += 2)
    {
        ans = max(ans, ans + b[i] + b[i + 1]);
        if(ans + b[i] + b[i + 1]<ans)
        {
            break;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}