#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct ST
{
    const int INF = 999999;
    ST(T a[], int n)
    {
        siz = n;
        maxv.resize(n + 1);
        minv.resize(n + 1);
        scmaxv.resize(n + 1);
        scminv.resize(n + 1);
        int t = __lg(n) + 1;
        for (int i = 0; i <= n; i++)
            maxv[i].resize(t), minv[i].resize(t), scmaxv[i].resize(t), scminv[i].resize(t);
        for (int i = 0; i <= n; i++)
            maxv[i][0] = minv[i][0] = a[i], scmaxv[i][0] = -INF, scminv[i][0] = INF;
        for (int j = 1; j < t; j++)
        {
            for (int i = 0; i <= n - (1 << j) + 1; i++)
            {
                if (maxv[i + (1 << (j - 1))][j - 1] > maxv[i][j])
                {
                    scmaxv[i][j] = maxv[i][j];
                    maxv[i][j] = maxv[i + (1 << (j - 1))][j - 1];
                }
                if(maxv[i + (1 << (j - 1))][j - 1]>scmaxv[i][j])
                    scmaxv[i][j] = maxv[i + (1 << (j - 1))][j - 1];
                if (minv[i + (1 << (j - 1))][j - 1] < minv[i][j])
                {
                    scminv[i][j] = minv[i][j];
                    minv[i][j] = minv[i + (1 << (j - 1))][j - 1];
                }
                if(minv[i + (1 << (j - 1))][j - 1]<scminv[i][j])
                    scminv[i][j] = minv[i + (1 << (j - 1))][j - 1];
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
    T getscmin(int l, int r)
    {
        int k = __lg(r - l + 1);
        return min(scminv[l][k], scminv[r - (1 << k) + 1][k]);
    }
    T getscmax(int l, int r)
    {
        int k = __lg(r - l + 1);
        return max(scmaxv[l][k], scmaxv[r - (1 << k) + 1][k]);
    }

private:
    int siz = 0;
    vector<vector<T>> maxv, minv, scmaxv, scminv;
};

void solve()
{
    int n, q;
    cin >> n >> q;
    int a[n+1];
    for (int i = 0; i <= n-1; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
    }
    ST<int> st(a, n);
    int l, r;
    int ans;
    while (q--)
    {
        cin >> l >> r;
        l--, r--;
        int k1 = max(a[l], a[l + 1]);
        int k2 = min(a[l], a[l + 1]);
        int index = l+4;
    //    cout<<index<<endl;
        int t1 = st.getmin(index, r);
        cout<<t1<<endl;
        int t2 = st.getscmin(index, r);
    //    cout<<t2<<endl;
        ans = (k1 - t1) * (k1 + t1) + (k2 - t2) * (k2 + t2);
     //   cout<<ans<<endl;
        while (index <= r - 3)
        {
            index++;
            auto now = a[index];
            if (now > k1)
            {
                k2 = k1;
                k1 = now;
            }
            else if (now > k2)
            {
                k2 = now;
            }
            t1 = st.getmin(index, r);
            t2 = st.getscmin(index, r);
            int res = (k1 - t1) * (k1 + t1) + (k2 - t2) * (k2 + t2);
            ans = max(ans, res);
        }
    //    cout << ans << endl;
    }
}
int main()
{
    //cout<<0x3f3f3f3f<<endl;
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}