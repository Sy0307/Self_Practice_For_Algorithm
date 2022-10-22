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

map<char, int> mp;
void solve()
{
    mp.clear();
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    fr(i, 1, n)
    {
        mp[s[i]]++;
    }
    int limit = n / k;
    fr(i, 1, k)
    {
        int cnt = 0;
        bool f = 1;
        fr(j, 0, 25)
        {
            auto c = j + 'a';
            if (mp[c])
            {
                mp[c]--;
                cnt++;
                if (cnt == limit)
                {
                    if(f)
                    {
                        cout<<char(c+1);
                    }
                    break;
                }
            }
            else if (f)
            {
                f = 0;
                cout << char(c);
            }
        }
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