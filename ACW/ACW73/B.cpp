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

string make(char a,char b,char c,char d)
{
    string tmp="";
    tmp+=a;
    tmp+=b;
    tmp+=c;
    tmp+=d;

    return tmp;
}
void solve()
{
    int n;
    cin >> n;
    map<string, int> mp;
    int ans = 0;
    string s1, s2, waste;
    fr(i, 1, n)
    {
        char a,b,c,d;
        cin>>a>>b>>c>>d;
        // a = to_string(a);
        // b = to_string(b);
        // c = to_string(c);
        // d = to_string(d);
        // ab
        // cd

        // ca
        // db

        // dc
        // ba

        // bd
        // ac
        string now = make(a,b,d,c);
        now = min(now, make(c , a , b , d));
        now = min(now, make(d , c , a , b));
        now = min(now, make(b , d , c , a));

        mp[now]++;

        cin >> waste;
    }
    cout << mp.size() << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}