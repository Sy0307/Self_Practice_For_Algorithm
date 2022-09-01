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
const int maxn = 1e5+10;
int n;
vector<int> edge[maxn];
int l[maxn], r[maxn];
ll dp[maxn][2];

void dfs(int fa,int now)
{
    for(auto &v:edge[now])
    {
        if(v==fa||!v) continue;
        dfs(now,v);
        dp[now][0]+=max(abs(l[now] - l[v])+dp[v][0],abs(l[now] - r[v])+dp[v][1]);
      //  cout<<dp[now][0]<<endl;
        dp[now][1]+=max(abs(r[now] - l[v])+dp[v][0],abs(r[now] - r[v])+dp[v][1]);
      //  cout<<dp[now][1]<<endl;
    }
}
void solve()
{
    memset(dp, 0, sizeof(dp));
    memset(edge,0,sizeof(edge));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(0,1);
    cout<<max(dp[1][0],dp[1][1])<<endl;
    
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}