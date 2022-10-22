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

    string s;
    cin >> s;

    int cnt = 0;
    cnt = count(s.begin(), s.end(), '1');
    if (cnt & 1)
    {
        cout << -1 << endl;
        return;
    }
    s = '?' + s;
    vector<int> v, ans;
    for(int i= 1;i<=2*n;i+=2)
    {
        if(s[i]!=s[i+1])
        {
            v.push_back(i);
        }
    }
    for(int i=0;i<v.size();i++)
    {
        int pos = v[i];
        if((i&1)==s[pos]-'0')
        {
            ans.push_back(pos);
        }
        else ans.push_back(pos+1);
    }
    cout<<ans.size();
    for(auto &x:ans)
    {
        cout<<" "<<x;
    }
    cout<<endl;
    for(int i=1;i<=2*n;i+=2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
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