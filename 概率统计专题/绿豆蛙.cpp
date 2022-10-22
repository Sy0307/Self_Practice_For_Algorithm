#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, double>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

vector<pii> edge[maxn];  //to and val 
double f[maxn];
int dg[maxn],in[maxn];
int n,m;
void topsort()
{
    queue<int> q;
    q.push(n);
    while(q.size())
    {
        int now = q.front();
        q.pop();
        for(auto &k:edge[now])
        {
            auto to = k.first;
            auto val = k.second;
            f[to]+=(f[now]+val)/(dg[to]*1.0);
            --in[to];
            if(!in[to])
            {
                q.push(to);
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    fr(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].push_back({v,w});
        edge[v].push_back({u,w});
        in[u]++ , dg[u]++;
    }
    topsort();
    cout<<fixed<<setprecision(2)<<f[1]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}