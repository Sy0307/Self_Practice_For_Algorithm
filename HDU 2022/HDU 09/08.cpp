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

vector<int> breakdown(int N)
{
    vector<int> result(sqrt(N)+1,-1);
    int cnt = 1;
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        { // 如果 i 能够整除 N，说明 i 为 N 的一个质因子。
            while (N % i == 0)
                N /= i;
            result[cnt++] = i;
        }
    }
    if (N != 1)
    { // 说明再经过操作之后 N 留下了一个素数
        result[cnt++] = N;
    }
    result[0] = cnt-1;
    return result;
}
int n;
const int maxn = 1e7 + 5;
bool vis[maxn];
void solve()
{
    int a,b;
    cin>>a>>b;
    if(__gcd(a,b)==1)
    {
        cout<<1<<" "<<1<<endl;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
    }
    auto fa = breakdown(a);
    auto fb = breakdown(b);
    int cnt = 0;
    //上面求出了两个数的所有质因子

    //筛法
    for(int k = 1;k<=fa[0];k++)
    {
        auto i = fa[k];
        if(!vis[i]) cnt++; 
        vis[i] = 1;
        for(int j = 2;i*j<=n;j++)
        {
            if(!vis[i*j]) cnt++;
            vis[i*j] = 1;
        }
    }
    for(int k = 1;k<=fb[0];k++)
    {
        auto i = fb[k];
        if(!vis[i]) cnt++; 
        vis[i] = 1;
        for(int j = 2;i*j<=n;j++)
        {
            if(!vis[i*j]) cnt++;
            vis[i*j] = 1;
            if(i%vis[j]==0)
            {
                break;
            }
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     if(!vis[i]) cout<<i<<" ";
    // }
    cout<<2<<" ";
    cout<<n - cnt<<endl;
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin>>n>>T;
    while (T--)
    {
        solve();
    }
    return 0;
}