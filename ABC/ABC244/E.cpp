#include<bits/stdc++.h>
using namespace std;

const int N = 2007;
const int mod = 998244353;
#define add(a,b) (a) = (a+b)%mod;

vector<int> edge[N];
int f[N][N][2];
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    int k,s,t,x;
    cin>>k>>s>>t>>x;
    
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    f[0][s][x==s] = 1;
    for(int i=0;i<k;i++)
        for(int u =1;u<=n;u++)
            for(int k=0;k<=1;k++)
                if(!f[i][u][k]) continue;
                else
                {
                    for(auto v:edge[u])
                    {
                        int tar = (k^(v==x));
                        add(f[i+1][v][tar],f[i][u][k]);
                    }
                }
    cout<<f[k][t][0]<<endl;
    return 0;
}