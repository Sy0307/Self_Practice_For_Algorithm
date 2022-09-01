#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int t = x;
    vector<int> a(n, 0);
    if (x & 1)
    {
        for (int i = 0; i < n && x; i++)
        {
            if (s[i] == '1' && x)
            {
                a[i] = 1;
                x--;
            }
        }
        if (x != 0)
            a[n - 1] += x;
    }
    else
    {
        for (int i = 0; i < n && x; i++)
        {
            if (s[i] == '0' && x)
            {
                a[i] = 1;
                x--;
            }
        }
        if (x != 0)
            a[n - 1] += x;
    }
    for (int i = 0; i < n; i++)
    {
        if ((t - a[i]) % 2 == 0)
        {
            cout << s[i];
        }
        else
        {
            if (s[i]=='1')
                cout << 0;
            else
                cout << 1;
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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
    return 0;
}