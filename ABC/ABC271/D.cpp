#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
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

int n,m;
int f[110][100010];
int a[110] , b[110];
void solve()
{
    cin>>n>>m;
    f[0][0] = 1;
    fr(i,1,n)
    {
        cin>>a[i]>>b[i];
        fr(j,0,m)
        {
            if(j>=a[i])
            {
                f[i][j]|=f[i-1][j-a[i]];
            }
            if(j>=b[i])
            {
                f[i][j]|=f[i-1][j-b[i]];
            }
        }
    }

    if(!f[n][m])
    {
        cout<<"No"<<endl;
    }
    else 
    {
        cout<<"Yes"<<endl;
        vector<char> ans;
        int now = m;
        for(int i = n;i>0;i--)
        {
            if(now>=a[i] && f[i-1][now-a[i]])
            {
                ans.push_back('H');
                now-=a[i];
            }
            else 
            {
                ans.push_back('T');
                now-=b[i];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            cout<<ans[i];
        }
        cout<<endl;
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