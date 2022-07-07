#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int dis[maxn];
int t[maxn]={0};
vector<int> edge[maxn];
bool vis[maxn]={0};
void add(int a,int b)
{
    edge[a].push_back(b);
    t[b]++;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(b,a);
    }
    using pii = pair<int,int> ;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    memset(dis,0x3f,sizeof(dis));
    dis[n] = 0;
    pq.push({0,n});
    while(pq.size())
    {
        auto now = pq.top();
        pq.pop();
        if(vis[now.second])
            continue;
        vis[now.second] = 1;
        for(auto k:edge[now.second])
        {
            if(dis[k]>now.first+t[k])
            {
                dis[k] =  now.first+t[k];
                pq.push({dis[k],k});
            }
            t[k]--;
        }

    }
    cout<<dis[1]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    solve();
}