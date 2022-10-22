#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
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

void solve()
{
    int n;
    cin >> n;
    map<string, int> mp;
    string s1[n + 1];
    fr(i, 1, n)
    {
        cin >> s1[i];
        mp[s1[i]]++;
    }
    string s2[n + 1];
    fr(i, 1, n)
    {
        cin >> s2[i];
        mp[s2[i]]++;
    }
    string s3[n + 1];
    fr(i, 1, n)
    {
        cin >> s3[i];
        mp[s3[i]]++;
    }

    vector<int> k(3);
    fr(i,1,n)
    {
        if(mp[s1[i]]==1)
        {
            k[0]+=3;
        }
        else if(mp[s1[i]]==2)
        {
            k[0]+=1;
        }
        else if(mp[s1[i]]==3)
        {
            k[0]+=0;
        }
    }
    fr(i,1,n)
    {
        if(mp[s2[i]]==1)
        {
            k[1]+=3;
        }
        else if(mp[s2[i]]==2)
        {
            k[1]+=1;
        }
        else if(mp[s2[i]]==3)
        {
            k[1]+=0;
        }
    }
    fr(i,1,n)
    {
        if(mp[s3[i]]==1)
        {
            k[2]+=3;
        }
        else if(mp[s3[i]]==2)
        {
            k[2]+=1;
        }
        else if(mp[s3[i]]==3)
        {
            k[2]+=0;
        }
    }
    cout<<k<<endl;
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