#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve()
{
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    bool f = 0;
    for (auto &now : s)
    {
        if (now != c)
        {
            f = 1;
        }
    }
    if (!f)
    {
        cout << "0" << endl;
        return;
    }

    if (s[n - 1] == c)
    {
        cout << 1 << endl;
        cout << n << endl;
        return;
    }
    f = 0;
    for (int i = 2; i <= n; i++)
    {
        int k = 0;
        for (int j = i; j <= n; j += i)
        {
            if (s[j - 1] != c)
            {
                k = 1;
                break;
            }
        }
        if (k == 0)
        {
            cout << 1 << endl;
            ;
            cout << i << endl;
            return;
        }
    }
    cout << 2 << endl;
    cout << n << " ";
    for (int i = 1; i < n; i++)
    {
        if (n % i != 0)
        {
            cout << i << endl;
            return;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}