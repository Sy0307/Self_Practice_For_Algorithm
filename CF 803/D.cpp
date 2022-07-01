#include <bits/stdc++.h>
using namespace std;

bool check(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    int cnt = 0;
    int x;
    for (int i = l; i <= r; i++)
    {
        cin >> x;
        if (x >= l && x <= r)
        {
            cnt++;
        }
    }
    return cnt & 1;
}
void solve()
{
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (!check(l, mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << "! " << l << endl;
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