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

bool vis[30];
int fa[30];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool same(int a,int b)
{
    return find(a) == find(b);
}
map<int,int> mp;
void solve()
{
    mp.clear();
    memset(vis, 0, sizeof(vis));
    int n;
    cin >> n;
    string s;
    fr(i, 0, 25) fa[i] = i;
    cin >> s;
    s = " " + s;
    string ans = "";
    int cnt = 0;
    fr(i, 1, n)
    {
        int j = s[i] - 'a';
        if (!mp[j])
        {
            cnt++;
            fr(k, 0, 25)
            {
                if (!vis[k] && (!same(j, k) || cnt == 26))
                {
                    mp[j] = k + 1;
                    vis[k] = 1;
                    fa[find(j)] = find(k);
                    break;
                }
            }
        }

        ans += char(mp[s[i] - 'a'] + 'a' - 1);
    }
    cout<<ans<<endl;
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