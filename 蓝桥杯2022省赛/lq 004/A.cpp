#include<bits/stdc++.h>
using namespace std;

int T;
int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        int l,r,a;
        cin>>l>>r>>a;
        int ans = r/a+r%a;
        int tmp = r/a*a-1;
        if(tmp>=l)
        {
            ans = max(ans,tmp/a+tmp%a);
        }
        cout<<ans<<endl;
    }
    return 0;
}