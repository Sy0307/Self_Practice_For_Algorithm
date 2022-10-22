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
    for (int i = 1; i <= 25; i++)
    {
        cout << "? 1 " << i + 1 << endl;
        long long len1, len2;
        cin >> len1;
        if (len1 == -1)
        {
            cout << "! " << i << endl;
            return;
        }
        cout << "? " << i + 1 << " 1" << endl;
        cin >> len2;
        if (len1 != len2)
        {
            cout << "! " << len1 + len2 << endl;
            return;
        }
    }
    return;
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