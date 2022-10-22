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

void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    if (s == "Monday")
    {
        ans = 5;
    }
    else if (s == "Tuesday")
    {
        ans = 4;
    }
    else if (s == "Wednesday")
    {
        ans = 3;
    }
    else if (s == "Thursday")
    {
        ans = 2;
    }
    else if (s == "Friday")
    {
        ans = 1;
    }
    else
    {
        ans = 0;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}