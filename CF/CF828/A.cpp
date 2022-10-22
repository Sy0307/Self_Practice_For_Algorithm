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

map<int,char>  mp;
void solve()
{
    string s;

    int n ; 
    cin>>n;
    vector<int> a(n);
    cin>>a;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        mp[a[i]] = '?';
    }
    for(int i=0;i<n;i++){
        int now = a[i];
        if(s[i]!=mp[now]&&mp[now]!='?')
        {
            cout<<"NO"<<endl;
            return ;
        }
        else mp[now] = s[i];
    }
    cout<<"YES"<<endl;
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