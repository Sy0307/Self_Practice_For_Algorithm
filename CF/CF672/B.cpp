#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define endl '\n'
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
istream &operator>>(istream &in, vector<int> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
ostream &operator<<(ostream &out, vector<int> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}

#define int ll
int a[40] ; 
void solve()
{
    int n ; 
    cin>>n;
    memset(a,0,sizeof(a));
    int ans = 0 ;
    fr(i,1,n)
    {
        int x;
        cin>>x;
        int mx =  0 ;
        fr(j,0,31)
        {
            if((1<<j)&x)
            {
                mx = max(mx,j);
            }
        
        }
        ans+=a[mx];
        a[mx]++;
     //   cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
signed main()
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