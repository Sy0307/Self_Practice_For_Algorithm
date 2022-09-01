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

int n,m;
void solve()
{
    cin>>n>>m;
    vector<int> a(n+2);
    fr(i,1,n)
    {
        cin>>a[i];
    }
    a[0] = a[n+1] = -1;
    ll ans = 1,sum = 0;
    fr(i,2,n)
    {
        if(a[i]!=a[i-1])
        {
            sum+=i,ans+=sum;
        }
        else
        {
            sum++;
            ans+=sum;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}