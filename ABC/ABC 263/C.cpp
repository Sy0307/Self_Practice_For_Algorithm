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

int a[maxn];
int n,m;
void dfs(int now,int step)
{
    if(step==n+1)
    {
        fr(i,1,n)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    fr(i,now+1,m)
    {
        a[step] = i;  
        dfs(i,step+1);
    }
}
void solve()
{
    cin>>n>>m;
    dfs(0,1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}