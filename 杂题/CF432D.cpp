#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e6 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

char a[maxn];
int suf[maxn],cnt[maxn],ans1[maxn];
int tot ; 
void solve()
{
    cin>>a+1;
    int n = strlen(a+1);
    //kmp
    for(int i=2,j = 0;i<=n;i++)
    {
        while(j>0&&a[i]!=a[1+j])
        {
            j = suf[j];
        }
        if(a[i]==a[j+1]) j++;
        suf[i] = j;
    }
    //kmp end
    fr(i,0,n)
    {
        cnt[i] = 1;
    }
    for(int i = n;i>=1;i--)
    {
        cnt[suf[i]] += cnt[i];
    }
    int last = suf[n];
    while(last)
    {
        ans1[tot] = last;
        tot++;
        last = suf[last];
    }
    cout<<tot+1<<endl;
    for(int i = tot-1;i>=0;i--)
    {
        cout<<ans1[i]<<" "<<cnt[ans1[i]]<<endl;
    }
    cout<<n<<" "<<1<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}