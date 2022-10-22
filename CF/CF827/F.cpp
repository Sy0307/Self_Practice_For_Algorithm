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

bool check(map<char, int> &mp1, map<char, int>& mp2)
{
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (mp1[c] < mp2[c])
            return true;
        else if (mp1[c] > mp2[c])
            return false;
        else
            continue;
    }
    return true;
}
void solve()
{
    map<char, int> mp1;
    map<char, int> mp2;
    int q;
    cin >> q;
    while (q--)
    {
        int op, t;
        string s;
        int c[130] = {0};
        cin >> op >> t >> s;
        if (op == 1)
        {
            for (auto now : s)
            {
                c[now - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                mp1[char(i + 'a')] += c[i + 'a'] * t;
            }

            if (check(mp1, mp2))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            for (auto now : s)
            {
                c[now - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                mp2[char(i + 'a')] += c[i + 'a'] * t;
            }

            if (check(mp1, mp2))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
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