#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 5e5 + 10;
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

int a[maxn];
bool vis[maxn]={0};
#define int long long
void solve()
{
    int n, t;
    cin >> n >> t;
    int ans = n;
    int sum = 0;
    int cnt = 0;
    fr(i, 1, n) cin >> a[i], sum += a[i];
    while (1)
    {
        cnt += ans * (t / sum);
        t %= sum;
        bool f = 0;
        fr(i, 1, n)
        {
            if (vis[i])
                continue;
            if (t >= a[i])
            {
                t -= a[i];
                vis[i] = 0;
                cnt++;
                f = 1;
            }
            else
            {
                vis[i] = 1;
                sum -= a[i];
                ans--;
            }
        }
        if(!f) break;
    }
    cout<<cnt<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}