#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                ans.push_back({i+1,j+1});
            }
        }
    }
    bool f = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (b[i] > b[j])
            {
                if (a[i] == a[j])
                {
                    swap(b[i], b[j]);
                    ans.push_back({i+1, j+1});
                }
                else
                {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }

    {
        cout << ans.size() << endl;
        for (auto &k : ans)
        {
            cout << k[0] << " " << k[1] << endl;
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