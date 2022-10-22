#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 5e5 + 10;
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
//

struct Trie
{
    int ch[maxn][10], sz = 0, val[maxn];
    int get_idx(char c)
    {
        if (c == 'A')
            return 1;
        if (c == 'G')
            return 2;
        if (c == 'C')
            return 3;
        if (c == 'T')
            return 4;
        if (c == '?')
            return 5;
        if (c == '*')
            return 6;
        return -1;
    }
    void clear()
    {
        sz = 0;
        memset(ch, 0, sizeof(ch));
    }

    void insert(char a[])
    {
        int u = 0, len = strlen(a + 1);
        for (int i = 1; i <= len; i++)
        {
            int x = get_idx(a[i]);
            if (!ch[u][x])
                ch[u][x] = ++sz;
            u = ch[u][x];
        }
        val[u]++;
    }
};
Trie trie;
char virus[maxn];
int n, l;
int ans = 0;
bitset<1007> vis[maxn];

void dfs(int step, int now)
{
    if (step == l + 1)
    {
        ans += trie.val[now];
        trie.val[now] = 0;
        return;
    }
    if(vis[now][step]) return;
    
    int x = trie.get_idx(virus[step]);
    vis[now][step] = 1;
    
    if(x>=1&&x<=4)
    {
        if(trie.ch[now][x])
            dfs(step+1, trie.ch[now][x]);
    }
    if(x==5)
    {
        fr(i,1,4)
        {
            if(trie.ch[now][i])
                dfs(step+1, trie.ch[now][i]);
        }
    }
    if(x==6)
    {
        dfs(step+1, now);
        fr(i,1,4)
        {
            if(trie.ch[now][i])
            {
                dfs(step+1, trie.ch[now][i]);
                dfs(step, trie.ch[now][i]);
            }
        }
    }

}
void solve()
{
    cin >> virus + 1;
    l = strlen(virus + 1);

    cin >> n;
    trie.clear();

    fr(i, 1, n)
    {
        char RNA[maxn];
        cin >> RNA + 1;
        trie.insert(RNA);
    }
    dfs(1, 0);
    cout << n - ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}