#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;

vector<string> er;

int solve(string a, string b)
{
    int l = 0;
    int m = a.size();
    int n = b.size();

    for (int i = 0; i < m; i++)
    {
        if (a[i] == b[l])
            l++;
        if (l == n)
            break;
    }
    return n + m - 2 * l;
}

signed main()
{
    er.clear();
    int a = 1;
    for (int i = 0; i < 61; i++)
    {
        er.push_back(to_string(a));
        a *= 2;
    }

    int T;
    cin >> T;
    while (T--)
    {
        cin >> a;
        int ans = 1e9 + 10;

        int n = er.size();
        for (int i = 0; i < n; i++)
            ans = min(solve(to_string(a), er[i]), ans);

        cout <<ans << endl;
    }
}
