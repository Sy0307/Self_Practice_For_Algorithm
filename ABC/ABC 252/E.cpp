#include<bits/stdc++.h>
using namespace std;
const int maxn = (2e5 + 5) *2;

using pii = pair<int,int> ; 
vector<vector<int>> edge[maxn];
int d[maxn];
int n,m; 
bool vis[maxn];
void dijk()
{
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,1});
    d[1] = 0;
    while(q.size())
    {
        auto now = q.top();
        int t = now.second;
        q.pop();
        if(vis[t]) continue;

        vis[t] = 1;
    //    d[t]  = 1;
        for(auto &c:edge[t])
        {
            int k = c[0];
            int v = c[1];
            if(d[k] > d[t]+v)
            {
                d[k] = d[t]+v;
                q.push({d[k],k});
                
            }
        }
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int a,b,v;
    
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>v;
        edge[a].push_back({b,v,i});
        edge[b].push_back({a,v,i});    
    }
    dijk();

    for(int i=2;i<=n;i++)
    {
        for(auto c:edge[i])
        {
            int t = c[0];
            int w = c[1];
            if(d[i] == d[t] + w)
            {
                cout<<c[2]<<" ";
                break;
            }
        }
    }
    return 0;
}