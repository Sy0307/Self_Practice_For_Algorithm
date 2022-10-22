#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2010;
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

char s[20000010];
int f[maxn][maxn];
bool dfs(int L,int R)
{
    if(f[L][R]!=-1)
        return f[L][R];
    if(L+1==R) return s[L]!=s[R];
    int flag = 0;
     if ((dfs(L + 2, R) || s[L] < s[L + 1]) && (dfs(L + 1, R - 1) || s[L] < s[R]))flag = 1;
    //a 选 s[R]  b 选 s[R - 1]                a 选s[R]   b选s[L]
    if ((dfs(L, R - 2) || s[R] < s[R - 1]) && (dfs(L + 1, R - 1) || s[R] < s[L]))flag = 1;

    return f[L][R] = flag;
}
void solve()
{
    cin>>(s+1);
    int n = strlen(s+1);
    fr(i,1,n)
        fr(j,1,n)
            f[i][j] = -1;
    if(dfs(1,n)) cout<<"Alice"<<endl;
    else cout<<"Draw"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}