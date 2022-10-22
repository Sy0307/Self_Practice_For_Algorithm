#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

#define LL long long
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 10;

char s[maxn];
LL ans;

struct PalindromicTree
{
    const static int maxn = 1e6 + 10;
    int next[maxn][26], last, sz, tot;
    int fail[maxn], len[maxn];
    LL cnt[maxn];
    char s[maxn];
    void debug()
    {
        for (int i = 0; i < 20; i++)
        {
            cout << cnt[i] << " ";
        }
        cout << endl;
    }
    void Clear()
    {
        len[1] = -1;
        len[2] = 0;
        fail[2] = fail[1] = 1;
        last = (sz = 3) - 1;
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
        for (int i = sz - 1; i > 2; i--)
            if (fail[i] > 2)
                cnt[fail[i]] += cnt[i];
    }
} solve[6];

void dfs(int x, int y)
{
    // printf("%d %d\n", x, y);
    ans += (solve[0].cnt[x] * solve[1].cnt[y] > 0);
    cout << ans << endl;
    for (int i = 0; i < 26; i++)
        if (solve[0].next[x][i] && solve[1].next[y][i])
            dfs(solve[0].next[x][i], solve[1].next[y][i]);
}

int main()
{
    int t, cas = 0;
    t = 1;
    while (t--)
    {
        for (int i = 0; i < 2; i++)
        {
            solve[i].Clear();
            scanf("%s", s);
            for (int j = 0; s[j]; j++)
                solve[i].add(s[j]);
            solve[i].work();
            if(i==1)
                solve[i].debug();
        }
        ans = 0;
        for (int i = 1; i <= 2; i++)
            dfs(i, i);
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}