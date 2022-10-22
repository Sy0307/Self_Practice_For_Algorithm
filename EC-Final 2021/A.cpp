#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
const int maxn = 1e5 + 5;
int n;
int depth[maxn];
int son[maxn];
bool vis[maxn];
vector<int> edge[maxn];
void dfs(int x, int dep)
{
    vis[x] = 1;
    depth[x] = dep;
    son[x]++;
    for (auto &i : edge[x])
        if (!vis[i])
        {
            //    if(x==3) cout<<i<<"！"<<endl;
            dfs(i, dep + 1);
            son[x] += son[i];
        }
    //   if(x==3) cout<<"SUC"<<son[3]<<endl;
}
void solve()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        edge[i].clear();
    }
    for (int i = 0; i <= n; i++)
    {
        depth[i] = 0;
        son[i] = 0;
        vis[i] = 0;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1, 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << depth[i] << " " << n - son[i] + 1 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}