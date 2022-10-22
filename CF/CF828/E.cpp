#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
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

#define int ll
map<int, int> mp;
vector<pii> fac;
int a, b, c, d;
void fj(int n)
{
    fr(i, 2, sqrt(n))
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            mp[i] += cnt;
        }
    }
    if (n > 1)
    {
        mp[n]++;
    }
}
bool flag = 0;
int ans_x = 0, ans_y = 0;
void dfs(int id, int k1, int k2)
{
    if (id == fac.size())
    {
        int x = ((a / k1) + 1) * k1;
        int y = ((b / k2) + 1) * k2;
        if (x <= c && y <= d)
        {
            flag = 1;
            ans_x = x;
            ans_y = y;
        }
        return;
    }
    int p = fac[id].first;
    int cnt = fac[id].second;
    int pow = 1;
    fr(i, 1, cnt)
    {
        pow *= p;
    }
    int res = 1;
    fr(i, 0, cnt)
    {
        dfs(id + 1, k1 * res, k2 * (pow / res));
        res *= p;
    }
}
void solve()
{
    mp.clear();
    fac.clear();
    flag = 0;
    cin>>a>>b>>c>>d;
    fj(a);
    fj(b);
    for(auto p:mp)
    {
        fac.push_back(p);
    }
    dfs(0, 1, 1);
    if(flag)
    {
        cout<<ans_x<<" "<<ans_y<<endl;
    }
    else
    {
        cout<<"-1 -1"<<endl;
    }
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