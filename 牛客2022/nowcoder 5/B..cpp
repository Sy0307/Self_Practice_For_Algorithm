#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n,k;
    cin >> n >> k;
    if (n <= k * 2)
        cout << -1 << endl;
    else
        cout << n + 1 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}