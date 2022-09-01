#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int N = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define ford(i, a, b) for(int i = a; i >= b; i--)
#define forall(i, a) for(auto &i : a)

vector<int> edge[N];
int fa[N];
int n, m, a[N];
int pre[N];
int mp[N];
int x, y;
bool st[N];
int color[N];

void init()
{
    fr(i, 1, n)
    {
        fa[i] = i;
    }
}
void add(int a, int b)
{
    edge[a].push_back(b);
}
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void bfs()
{
    queue<int> q;
    q.push(x);
    st[x] = 1;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        if (t == y) continue;
        for (auto& v : edge[t])
        {
            if (st[v]) continue;
            st[v] = 1;
            pre[v] = t;
            q.push(v);
        }
    }
}
void dfs(int u,int fa,int c)
{
    color[u] = c;
    for(auto &v:edge[u])
    {
        if(fa==v)
         continue;
        if(mp[v]) continue;
        if(color[v]) continue;
        dfs(v,u,c);
    }
}
void solve()
{
    cin >> n;
    init();
    fr(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) x = a, y = b;
        else
        {
            add(a, b);
            add(b, a);
            fa[find(a)] = find(b);
        }
    }
    mp[x] = 1;
    mp[y] = 1;
    bfs();
    for (int i = y;i != x;i = pre[i]) mp[i] = 1;
    fr(i, 1, n)
    {
        if (mp[i])
        {
            dfs(i, 0, i);
        }
    }
    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (color[a] != color[b])
            cout << "No" << endl;
        else cout << "Yes" << endl;
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}