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

void solve()
{
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;
    vector<int> pos;
    if(c=='g')
    {
        cout<<0<<endl;
        return ;
    }
    fr(i,0,n-1)
    {
        if(s[i]=='g')
        {
            pos.push_back(i);
        }
    }
    //cout<<pos[0]+n<<endl;
    pos.push_back(pos.back() - n);
    pos.push_back(pos[0]+n);
    sort(pos.begin(),pos.end());
  //  cout<<pos.size()<<endl;
    int ans=  0; 
    fr(i,0,n-1)
    {
        if(s[i]==c)
        {
            auto it1 = lower_bound(pos.begin(),pos.end(),i) ;
            auto it2 = upper_bound(pos.begin(),pos.end(),i) ;
            // cout<<i<<" "<<it2<<endl;
            ans = max(ans,int(i - *it1));
            ans = max(ans,int(*it2 - i));
        }
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