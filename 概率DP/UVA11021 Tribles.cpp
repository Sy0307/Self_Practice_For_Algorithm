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

double f[maxn],p[maxn];
void solve(int number)
{
    int m,n,k;
    memset(f,0,sizeof(f));
    memset(p,0,sizeof(p));
    cin>>n>>k>>m;
    fr(i,0,n-1)
    {
        cin>>p[i];
    }
    fr(i,1,m)
    {
        fr(j,0,n)
        {
            f[i]+=p[j]*pow(f[i-1] , j);
        }
    }
    cout<<"Case #"<<number<<": "<<pow(f[m],k)<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    fr(i,1,T)
    {
        solve(i);
    }
    return 0;
}