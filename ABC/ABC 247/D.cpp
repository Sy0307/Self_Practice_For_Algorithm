#include<bits/stdc++.h>
using namespace std;
struct square
{
    int l;
    int r;
    int val;
    int pre;
}a[1000010];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int cnt=  0;
    int first = 0;
    a[0] = (square){-1,-1,0,0};
    for(int i=1;i<=n;i++)
    {
        int sign;
        cin>>sign;
        if(sign==1)
        {
            int x,c;
            cin>>x>>c;
            cnt++;
            a[cnt].l = a[cnt-1].r+1;
            a[cnt].r = a[cnt].l+c;
            a[cnt].val = x;
            a[cnt].pre = x*c+a[cnt-1].pre;
       //     cout<<a[cnt].pre<<endl;
        }
        else
        {
            int c;
            cin>>c;
            int l = first,r = cnt;
            while(l<=r)
            {
                int mid = (l+r)>>1;
                if(a[mid].l<=c)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            c-=a[r].l;
            first = r;
            cout<<"r = "<<r<<endl;
            int ans = c*a[r].val+a[r-1].pre;
            cout<<ans<<endl;
        }
    }
    return 0;
}