#include <bits/stdc++.h>
using namespace std;

bool judge(string s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
            return false;
    }
    return true;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (judge(s))
    {
        cout << 1 << endl;
        return;
    }
    else
    {
        if (k == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}