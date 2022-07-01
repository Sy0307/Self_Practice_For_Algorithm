#include<bits/stdc++.h>
using namespace std;

int out[200010];
int in[200010];
bool vis[200010];
vector<int> edge[200010];
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[b].push_back(a);
        in[a]++;
    }
    int ans = 0;
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(in[i]==0) q.push(i);
    while(q.size())
    {
        auto now = q.front();
        q.pop();
        ans++;
        
        for(auto v:edge[now])
        {
            in[v]--;
            if(in[v]==0)
                q.push(v);
        }
    }
    cout<<n-ans<<endl;
    return 0;
}