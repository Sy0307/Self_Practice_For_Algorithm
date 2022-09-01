#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    string ans = "";
    cin>>n;
    if(n<=3)
    {
        for(int i=0;i<n;i++)
        {
            ans+= i + 'a';
        }
    }
    else
    {
        int mid = n/2;
        for(int i=0;i<mid - 1;i++)
        {
            ans+= 'a';
        }
        if(n&1)
        {
            ans+="bc";
        }
        else  ans+='b';
        for(int i=0;i<mid;i++)
        {
            ans+="a";
        }
    }
    cout<<ans<<endl;
}
int main() {
ios::sync_with_stdio(false);
int T;cin>>T;
while(T--)
{
solve();
}
 return 0 ; 
}