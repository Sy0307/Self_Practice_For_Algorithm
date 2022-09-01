#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

int a[10];
int now[10];
bool vis[10];
bool dfs(int step)
{
    if(step==6)
    {
        return now[1]==now[2]&&now[3]==now[1]&&now[4]==now[5];
    }
    fr(i,1,5)
    if(!vis[i])
    {
        vis[i]=1;
        now[step]=a[i];
        if(dfs(step+1))
        {
            return 1;
        }
        vis[i]=0;
    }
    return false;
}
void solve()
{
    fr(i,1,5)
    {
        cin>>a[i];
    }
    if(dfs(1))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}