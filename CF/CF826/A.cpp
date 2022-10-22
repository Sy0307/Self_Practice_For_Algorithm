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

map<char,int> mp;
void solve()
{
    mp['L'] = 3;
    mp['M'] = 1;
    mp['S'] = 0;
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size();
    int n2 = s2.size();
    if (mp[s1[n1 - 1]] < mp[s2[n2 - 1]])
    {
        cout << "<" << endl;
        return;
    }
    else if (mp[s1[n1 - 1]] > mp[s2[n2 - 1]])
    {
        cout << ">" << endl;
        return;
    }
    else
    {
        if (s1.size() > s2.size())
        {
            if (s1[n1 - 1] == 'L')
                cout << ">" << endl;
            else
                cout << "<" << endl;
            return;
        }
        else if (s1.size() < s2.size())
        {
            if (s1[n1 - 1] == 'L')
                cout << "<" << endl;
            else
                cout << ">" << endl;
            return;
        }
        else
        {
            cout << "=" << endl;
            return;
        }
    }
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