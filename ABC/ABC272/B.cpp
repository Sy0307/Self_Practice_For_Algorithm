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

int peo[110][110];
void solve()
{
    int n,m;
    cin>>n>>m;
    fr(i,1,n)
    {
        int k ; 
        cin>>k;
        vector<int> a(k);
        fr(j,1,k)
        {
            cin>>a[j-1];
        }
        fr(j,0,k-1)
        {
            fr(l,0,k-1)
            {
                peo[a[j]][a[l]]=1;
                peo[a[l]][a[j]]=1;
            }
        }
    }
    fr(i,1,n)
    {
        fr(j,1,n)
        {
            if(peo[i][j]!=1)
            {
                cout<<"No"<<endl;;
                return ;
            }
        }
    }
    cout<<"Yes"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}