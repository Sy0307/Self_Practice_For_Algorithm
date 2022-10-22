#include <bits/stdc++.h>
using namespace std;

#define LL long long
using ll = long long;
const int maxn = 3e6 + 10;

int k;
// char s[maxn];
LL ans;

struct PalindromicTree
{
    const static int maxn = 1e6 + 10;
    int next[maxn][26], last, sz, tot;
    int fail[maxn], len[maxn];
    LL cnt[maxn] = {0};
    // void debug()
    // {
    //     for (int i = 0; i < 20; i++)
    //     {
    //         cout << cnt[i] << " ";
    //     }
    //     cout << endl;
    // }
    char s[maxn];
    void Clear()
    {
        len[1] = -1;
        len[2] = 0;
        fail[2] = fail[1] = 1;
        //  fail[3] = 1;
        sz = k + 1;
        last = 2;
        cnt[1] = cnt[2] = tot = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(next[1], 0, sizeof(next[1]));
        memset(next[2], 0, sizeof(next[2]));
    }
    int Node(int length)
    {
        memset(next[sz], 0, sizeof(next[sz]));
        len[sz] = length, cnt[sz] = 1;
        return sz++;
    }
    int getfail(int x)
    {
        while (s[tot] != s[tot - len[x] - 1])
            x = fail[x];
        return x;
    }
    int add(char pos)
    {
        int x = (s[++tot] = pos) - 'a', y = getfail(last);
        if (next[y][x])
            return ++cnt[last = next[y][x]];
        last = next[y][x] = Node(len[y] + 2);
        fail[last] = len[last] == 1 ? 2 : next[getfail(fail[y])][x];
        return cnt[last];
    }
    void work()
    {
        //    cout<<sz<<endl;
        for (int i = sz - 1; i > k; i--)
            if (fail[i] > 2)
                cnt[fail[i]] += cnt[i];
    }
} solve[6];
unordered_map<ll, int> mp;
void dfs(int siz, int now[], int step)
{
    ll t = 0;
    for (int j = 0, x = 1; j < siz; j++, x *= 26)
        t += now[j] * x;
    if (mp[t])
        return;
    else
        mp[t] = 1;
    // DEBUG
    //  cout<<step<<" ";
    //  for (int i = 0; i < siz; i++)
    //  {
    //      cout << now[i] << " ";
    //  }
    //  cout << endl;

    // DEBUG
    // cout<<"Attention";
    // cout<<solve[2].cnt[now[2]]<<endl;
    int tmp = solve[0].cnt[now[0]];
    for (int i = 1; i < siz; i++)
    {
        tmp *= solve[i].cnt[now[i]];
    }
    //  cout<<tmp<<endl;
    ans += (tmp > 0);
    int tmpnow[6];
    for (int i = 0; i < 26; i++)
    {
        bool f = 1;
        for (int j = 0; j < siz && f; j++)
        {
            if (solve[j].next[now[j]][i] <= 0)
            {
                f = 0;
                memset(tmpnow, -1, sizeof(tmpnow));
                continue;
            }
        }
        if (f)
        {
            //    ans++;
            for (int j = 0; j < siz; j++)
                tmpnow[j] = solve[j].next[now[j]][i];
            dfs(siz, tmpnow, step + 1);
        }
    }
}
int main()
{
    int t, cas = 0;
    t = 1;
    while (t--)
    {
        mp.clear();
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
        {
            solve[i].Clear();
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++)
                solve[i].add(s[j]);
            // if (i == 0)
            // solve[i].debug();
            solve[i].work();
        }
        ans = 0;
        for (int i = 1; i <= k; i++)
        {
            int now[6];
            for (int j = 0; j < k; j++)
                now[j] = i;
            dfs(k, now, 0);
        }
        printf("%lld\n", ans);
    }
    return 0;
}