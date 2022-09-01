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
const int maxn = 110;
int n, a[maxn];
int dp[maxn];
void dfs(int l,int r,int depth)
{
    if(l>r) 
    {
        return;
    }
    auto index = max_element(a+l,a+r+1) - a;
    dp[index] = depth;
    dfs(l,index-1,depth+1);
    dfs(index+1,r,depth+1);
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,n,0);
    for(int i=1;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
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