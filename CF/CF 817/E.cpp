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

ll f[1010][1010];
void solve()
{
    int n,m;
    cin>>n>>m;
    memset(f,0,sizeof(f));
    fr(i,1,n)
    {
        ll a,b;
        cin>>a>>b;
        f[a][b]+=a*b;
    }
    fr(i,1,1000)
    {
        fr(j,1,1000)
        {
            f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
        }
    }
    while(m--)
    {
        int a1,b1,a2,b2;
        cin>>a1>>b1>>a2>>b2;
        a1++,b1++,a2--,b2--;
        cout<<f[a2][b2]-f[a1-1][b2]-f[a2][b1-1]+f[a1-1][b1-1]<<endl;
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