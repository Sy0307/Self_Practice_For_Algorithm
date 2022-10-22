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

void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    auto check = [&](char c)
    {
        int cnt1 = 0, cnt2 = 0;
        for (auto i : s)
        {
            if (i == c)
                cnt1++;
        }
        for (auto i : t)
        {
            if (i == c)
                cnt2++;
        }
        return cnt1 != cnt2;
    };

    if (check('a') || check('b') || check('c'))
    {
        cout << "NO" << endl;
        return;
    }

    vector<int> b1, b2;
    string k1, k2;
    fr (i, 0, n - 1)
    {
        if (s[i] != 'b')
        {
            b1.push_back(i);
            k1 += s[i];
        }
    }

    fr (i, 0, n - 1)
    {
        if (t[i] != 'b')
        {
            b2.push_back(i);
            k2 += t[i];
        }
    }
    if (k1 != k2)
    {
        cout << "NO" << endl;
        return;
    }

    for (int i = 0; i < k1.size(); i++)
    {
        if (k1[i] == 'a')
        {
            if (b1[i] > b2[i])
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            if (b1[i] < b2[i])
            {
                cout << "NO" << endl;
                return;
                return;
            }
        }
    }
    cout << "YES" << endl;
    return;
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