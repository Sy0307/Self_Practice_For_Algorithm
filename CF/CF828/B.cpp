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
istream &operator>>(istream &in, vector<ll> &v)
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
void solve()
{
    int x= 0 ,y =  0;
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    ll ans =  0;
    cin>>a;
    fr(i,0,n-1)
    {
        ans+=a[i];
        if(a[i]%2==1)
        {
            x++;
        }
        else y++;
    }
    // x 奇数

    // 0 加偶数
    while(q--)
    {
        int op,val;
        cin>>op>>val;
        if(op==0)
        {
            ans+=y*val;
            if(val&1)
            {
                x+=y;
                y=0;
            }
        }
        else
        {
            ans+=x*val;
            if(val&1)
            {
                y+=x;
                x=0;
            }
        }
        cout<<ans<<endl;
    }
    

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