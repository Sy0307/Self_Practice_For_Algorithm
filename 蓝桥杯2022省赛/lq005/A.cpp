#include<bits/stdc++.h>
using namespace std;
int a[200010];
int f[200010][2];
bool judge(int l,int r)
{
    int cnt0 = 0;
    for(int i=l;i<=r;i++)
        if(a[i]<0)
        {
            cnt0++;
        }
    if(cnt0&1)
    return 1;
    else return 0;
}
int make(int l,int r)
{
    int ans = 1;
    for(int i=l;i<=r;i++)
    {
        ans*=a[i];
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int last = 1;
        int lans = 0,rans = -1;
        int cnt = 0;
        int ans = -1;
        int sign = -1;
        for(int i=1;i<=n+1;i++)
        {
            if(a[i]==0||i==n+1)
            {
            //    cout<<judge(last,i-1)<<endl;
                cnt++;
                if(judge(last,i-1))
                {
                    int index = last ;
                    bool f = 1;
                    for(int j=last;j<=i-1&&f;j++)
                        if(a[j]<0) 
                        {
                            index = j;
                            f = 0;
                        }
                //    cout<<index<<endl;
                    if(ans<make(index+1,i-1))
                    {
                        ans = make(index+1,i-1);
                        lans = index;
                        rans = n-i+1;
                    //    cout<<"LEFT ANS = "<<ans<<endl;
                    }
                //    cout<<"ANs= "<<ans<<endl;
                    f = 1;
                    index = i;
                    for(int j=i-1;j>=last&&f;j--)
                    {
                        if(a[j]<0)
                        {
                            index = j;
                            f = 0;
                        }
                    }
                //    cout<<make(last,index-1)<<endl;
                    if(ans<make(last,index-1))
                    {
                        ans = make(last,index-1);
                    //    cout<<"RIGHT"<<endl;
                        lans = last-1;
                        rans = n-index+1;
                    }
               //     cout<<"ANs= "<<ans<<endl;
                    
                }
                else
                {
                    if(ans<make(last,i))
                    {
                        ans = make(last,i);
                        lans = last;
                        rans = i;
                    }                    
                }
                last = i+1;
            }
        }
    //    cout<<ans<<endl;
        cout<<lans<<" "<<rans<<endl;
    }
        return 0;
}