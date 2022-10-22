#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second
#define mid (l + r >> 1)
#define ls id << 1
#define rs id << 1 | 1
#define file() freopen("File.txt", "r", stdin)
#define int long long
#define endl '\n'
using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e4 + 7, maxm = 1e6 + 5;


int n, MAX,k;
int s[maxn];
int cnt[maxn], tmp[maxn], sa[maxn], Rank[maxn], height[maxn];

inline void Sort()
{
    for (int i = 1; i <= MAX; i++)
        cnt[i] = 0;
    for (int i = 1; i <= n; i++)
        cnt[Rank[tmp[i]]]++; // 或 cnt[Rank[i]]++ 等效
    for (int i = 1; i <= MAX; i++)
        cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--)
        sa[cnt[Rank[tmp[i]]]--] = tmp[i], tmp[i] = 0;
}
inline void Get_SA()
{
    for (int i = 1; i <= n; i++)
        Rank[i] = s[i], tmp[i] = i;
    MAX = 255;
    Sort();
    for (int p = 1; p <= n; p <<= 1)
    {
        int num = 0;
        for (int i = n - p + 1; i <= n; i++)
            tmp[++num] = i; // 他们第二关键字为空，一定最靠前
        for (int i = 1; i <= n; i++)
            if (sa[i] > p)
                tmp[++num] = sa[i] - p;                 // 按上一次的排名从小到大枚举每个串，若可以成为第二关键字便加入
        Sort(), swap(Rank, tmp), MAX = Rank[sa[1]] = 1; // 注意一开始 Rank 是第一关键字，swap 后 tmp 才是第一关键字
        for (int i = 2; i <= n; i++)
            if (tmp[sa[i]] != tmp[sa[i - 1]] || tmp[sa[i] + p] != tmp[sa[i - 1] + p])
                Rank[sa[i]] = ++MAX;
            else
                Rank[sa[i]] = MAX;
        if (MAX == n)
            return;
    }
}

inline void Get_Height()
{
    for (int i = 1, j, tmp = 0; i <= n; i++)
    {
        if (Rank[i] == 1)
        {
            height[Rank[i]] = 0;
            continue;
        }
        if (tmp)
            tmp--;
        j = sa[Rank[i] - 1];
        while (i + tmp <= n && j + tmp <= n && s[i + tmp] == s[j + tmp])
            tmp++;
        height[Rank[i]] = tmp;
    }
}

int q[maxm], h, t = -1;

void solve()
{
    cin>>n>>k;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    Get_SA(), Get_Height();
    //区间最小值 维护队首为最小值
    //在所有最小值中取max
    for (int i = 2; i <= k - 1; i++)
    {
        while (h <= t && height[q[t]] >= height[i])
            --t;
        q[++t] = i;
    }
    int ans = 0;
    for (int i = k; i <= n; ++i)
    {
        while (h <= t && i - q[h] + 1 >= k)
            ++h; //去队首
        while (h <= t && height[q[t]] >= height[i])
            --t; //去队尾
        q[++t] = i;
        ans = max(ans, height[q[h]]);
    }
    cout << ans << endl;
}

signed main(void)
{
    //	file();
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }

    return 0;
}
