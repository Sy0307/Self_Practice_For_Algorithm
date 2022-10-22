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

vector<int> v[10] = {
    {7},
    {4},
    {2, 8},
    {1, 5},
    {3, 9},
    {6},
    {10}};

void solve()
{
    string s;
    cin >> s;
    s = '?' + s;
    bool ok = true;
    if (s[1] == '1')
    {
        cout << "No" << endl;
        return;
    }
    for (int i = 0; i < 7; i++)
        for (int j = i + 1; j < 7; j++)
        {
            bool tt = true;
            bool ok1 = false, ok2 = false;
            for (auto it : v[i])
                if (s[it] == '1')
                    ok1 = true;
            for (auto it : v[j])
                if (s[it] == '1')
                    ok2 = true;
            if (!ok1 || !ok2)
                tt = false;
            bool flag = false;
            for (int k = i + 1; k < j; k++)
            {
                bool all = true;
                for (auto it : v[k])
                {
                    if (s[it] != '0')
                        all = false;
                }
                flag |= all;
            }
            tt &= flag;
            if (tt)
            {
                cout << "Yes" << endl;
                return;
            }
        }
    cout << "No" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}