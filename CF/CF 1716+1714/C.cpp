#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

template <typename T>
struct ST
{
    ST(T a[], int n)
    {
        siz = n;
        maxv.resize(n + 1);
        minv.resize(n + 1);
        int t = __lg(n) + 1;
        for (int i = 1; i <= n; i++)
            maxv[i].resize(t), minv[i].resize(t);

        for (int i = 1; i <= n; i++)
            maxv[i][0] = minv[i][0] = a[i];
        for (int j = 1; j < t; j++)
        {
            for (int i = 1; i <= n - (1 << j) + 1; i++)
            {
                maxv[i][j] = max(maxv[i][j - 1], maxv[i + (1 << (j - 1))][j - 1]);
                minv[i][j] = min(minv[i][j - 1], minv[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T getmax(int l, int r)
    {
        int k = __lg(r - l + 1);
        return max(maxv[l][k], maxv[r - (1 << k) + 1][k]);
    }
    T getmin(int l, int r)
    {
        int k = __lg(r - l + 1);
        return min(minv[l][k], minv[r - (1 << k) + 1][k]);
    }

private:
    int siz = 0;
    vector<vector<T>> maxv, minv;
};

void solve()
{
    int n;
    cin >> n;

    int siz = 2 * n + 1;
    int k1[siz], k2[siz];
    int ans = INT_MAX;
    int nowt = 0;
    vector<vector<int>> a(3, vector<int>(n + 1, 0));

    auto handle = [&](int i, int j)
    {
        if (j > n)
            return;
        else if (nowt >= a[i][j])
            nowt++;
        else
            nowt = a[i][j] + 1;
    };
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    for (int i = 1; i <= n; i++)
    {
        k1[i] = k2[i] = a[1][i];
    }
    for (int i = 1; i <= n; i++)
    {
        k1[i + n] = k2[i + n] = a[2][n - i + 1];
    }

    reverse(k2 + 1, k2 + siz);
    for (int i = 1; i <= siz-1; i++)
    {
        k1[i] -= i;
        k2[i] -= i;
    }

    ST<int>s1(k1, siz - 1), s2(k2, siz - 1);

    for (int i = 1; i <= n; i += 2)
    {
        ans = min(ans, nowt + max(0, s1.getmax(i + 1, 2 * n - i + 1) + (i + 1) - nowt) + 2 * (n - i) + 1);
        ans = min(ans, nowt + max(0, s2.getmax(i, 2 * n - i) + i - nowt) + 2 * (n - i) + 1);

        handle(2, i);
        handle(2, i + 1);
        handle(1, i + 1);
        handle(1, i + 2);
    }
    cout << ans << endl;
    return;
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