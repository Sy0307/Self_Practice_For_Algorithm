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
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define ford(i, a, b) for(int i = a; i >= b; i--)
#define forall(i, a) for(auto &i : a)
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
    string a,b;
    cin>>a;
    cin>>b;
    if(a.size()>b.size())
    {
        cout<<"No"<<endl;
        return ;
    }
    else{
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
            {
                cout<<"No"<<endl;
                return ;
            }
        }
        cout<<"Yes"<<endl;
    }
}
int main() {
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
solve();
 return 0 ; 
}