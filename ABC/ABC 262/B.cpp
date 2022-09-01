#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e2 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

bool g[maxn][maxn];
void solve()
{
    int n,m;
    cin>>n>>m;
    fr(i,1,m)
    {
        int a,b;
        cin>>a>>b;
        g[a][b]=1;
        g[b][a]=1;
    }
    int ans = 0;
    fr(i,1,n)
    {
        fr(j,i+1,n)
        {
            fr(k,j+1,n)
            {
                if(i!=j and j!=k)
                {
                    if(g[i][j] and g[j][k] and g[k][i])
                    {
                        ans++;
                        //return;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}