#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

int n,k;
void solve()
{
    cin>>n>>k;
    vector<int> card(n+10,-1), cnt(n+10,0) , store(n+10,-1);
    set<int> s;

    fr(i,1,n)
    {
        int p;
        cin>>p;
        auto key = s.upper_bound(p);
        if(key==s.end())
        {
            s.insert(p);
            cnt[p]++;
        }
        else
        {
            store[p] = (*key);
            cnt[p] = cnt[(*key)] + 1;
            s.erase(key);
            s.insert(p);
        }
        if(cnt[p]==k)
        {
            s.erase(p);
            int x = p;
            fr(j,0,k-1)
            {
                card[x] = i;
                x = store[x];
            }
        }
    }
    fr(i,1,n)
    {
        cout<<card[i]<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}