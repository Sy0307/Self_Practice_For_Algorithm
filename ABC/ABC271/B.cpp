#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
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

vector<int> a[maxn];
void solve()
{
    int n,q;
    cin>>n>>q;
    fr(i,1,n)
    {
        int x;
        cin>>x;
        a[i].resize(x+1);
        fr(j,1,x)
        {
            int y;
            cin>>y;
            a[i][j] = y;
        }
    }
    fr(i,1,q)
    {
        int x,y;
        cin>>x>>y;
        cout<<a[x][y]<<endl;
    }
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}