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

string get(string &s)
{
    while (s.size() < 18)
    {
        s = '0' + s;
    }
    return s;
}
string tranform(ll x)
{
    string s = "";
    while (x)
    {
        if ((x % 10) & 1)
        {
            s = '1' + s;
        }
        else
            s = '0' + s;
        x /= 10;
    }
    s = get(s);
    return s;
}
void solve()
{
    int q;
    cin >> q;
    map<string, int> mp;
    while (q--)
    {
        char op;
        ll x;
        cin >> op;

        if (op == '+')
        {
            cin >> x;
            auto s = tranform(x);
            mp[s]++;
        }
        else if (op == '-')
        {
            cin >> x;
            auto s = tranform(x);
            mp[s]--;
        }
        else
        {
            string t;
            cin >> t;
            t = get(t);
            cout << mp[t] << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}