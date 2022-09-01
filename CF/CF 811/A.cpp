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

int t[maxn];
void solve()
{
    int n,H,M;
    cin>>n>>H>>M;
    int ans = 1440;
    int now = H*60+M;
    fr(i,1,n)
    {
        int a , b;
        cin>>a>>b;
        int t1 = H*60+M;
        int t2 = a*60+b;
        auto diff = t2-t1;
        if(diff<0) diff+=1440;
        ans = min(ans,diff);
    }
   // cout<<tmp<<endl;
    //cout<<now<<endl;
    cout<<ans/60<<" "<<ans%60<<endl;
    
    // if(tmp==n)
    // {

    // }
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