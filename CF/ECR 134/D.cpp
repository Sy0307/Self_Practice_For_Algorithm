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
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    cin>>a>>b;
    int c = 0;
    ford(j,29,0)
    {
        map<int,int> mp;
        c|=1<<j;
        fr(i,0,n-1)
        {
            mp[a[i]&c]++;
            mp[~b[i]&c]--;
        }
        bool f = 1;
        for(auto &x:a)
        {
            if(mp[x&c]!=0)
            {
                f = 0;
                break;
            }
        }
        if(!f)
        {
            c^=(1<<j);
        }
    }
    cout<<c<<endl;
    
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