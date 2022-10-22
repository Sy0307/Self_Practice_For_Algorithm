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

double f[maxn] , ans[maxn];
void solve()
{
    int n;
    cin>>n;
    ford(i,n-1,0)
    {
        f[i] = f[i+1]+(1.0*n) /(1.0*(n-i));
        ans[i] = (1.0*i)/(1.0*(n-i)) * (f[i]+1) +ans[i+1]+f[i+1]+1;
    }
    printf("%0.2lf",ans[0]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}