#include<bits/stdc++.h>
using namespace std;

int n,m,k;
struct node{
    int x,k;
};
struct edge{
    int v,c,next;
}g[10010];

int cnt = 0;
int d[1200][6010],w[6010],h[6010];
void add(int x,int y,int c)
{
    auto tmp = (edge){y,c,h[x]};
    g[++cnt] =tmp;
    h[x] =cnt;
}
int make()
{
    int s = 0;
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        s|=x<<i;
    }
    return s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    queue<node> q;
    for(int i=1;i<=n;i++)
    {
        w[i] = make();
    }
    for(int x,y,c,i=1;i<=m;i++)
    {
        cin>>x>>y;
        auto tmp = make();
        add(x,y,tmp);
    }
    memset(d,-1,sizeof(d));
    d[w[1]][1] = 0;
    q.push((node){1,w[1]});

    while(q.size())
    {
        auto t = q.front();
        int x = t.x;
        int y = t.k;
        for(int i=h[x];i;i=g[i].next)
        {
            int v = g[i].v;
            if(((y&g[i].c)==g[i].c)&&(d[y|w[g[i].v]][v] ==-1))
            {
                d[y|w[v]][v] = d[y][x]+1;
                q.push((node){v,y|w[v]});
            }
        }

        q.pop();
    }
    int ans = 999999999;
    for(int i=0;i<(1<<k);i++) if(~d[i][n]) ans = min(ans,d[i][n]);
    if(ans==999999999)
        cout<<"No Solution"<<endl;
    else cout<<ans<<endl;

    return 0;
}