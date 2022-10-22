#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
istream &operator>>(istream &in, vector<int> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
ostream &operator<<(ostream &out, vector<int> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}

const int maxn = 1e6 + 10;
int n, MAX;
char s[maxn];
int cnt[maxn], tmp[maxn], sa[maxn], Rank[maxn], Height[maxn];
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
            Height[Rank[i]] = 0;
            continue;
        }
        if (tmp)
            tmp--;
        j = sa[Rank[i] - 1];
        while (i + tmp <= n && j + tmp <= n && s[i + tmp] == s[j + tmp])
            tmp++;
        Height[Rank[i]] = tmp;
    }
}

void solve()
{
    cin >> (s + 1);
    int len = strlen(s + 1);
    s[len + 1] = '%';
    cin >> (s + len + 2);
    n = strlen(s + 1);

    Get_SA();
    Get_Height();

    int ans = 0;
    fr(i, 2, n)
    {
        if ((sa[i - 1] < len && sa[i] > len) || (sa[i - 1] > len  && sa[i] < len))
            ans = max(ans, Height[i]);
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}