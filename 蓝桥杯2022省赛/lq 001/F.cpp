#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

const int N = 61;
const int M = 1065;
int n,m;
int tot,was,mouth[M],all[M],c[N],t[N],ans,l,r,mid;
inline int read()
{
    char ch=getchar();int num=0;bool flag=false;
    while(ch<'0'||ch>'9'){if(ch=='-')flag=true;ch=getchar();}
    while(ch>='0'&&ch<='9'){num=num*10+ch-'0';ch=getchar();}
    return flag?-num:num;
}
inline  bool check(int x,int step)
{
    if(!x) return true;
    if(tot - was<all[mid]) return false;
 //   cout<<"SOS"<<endl;
    for(int i=step;i<=n;i++)
    if(t[i]>=mouth[x])
    {
        t[i]-=mouth[x];
        if(t[i]<mouth[1]) was+=t[i];
        if(mouth[x]==mouth[x-1])
        {
            if(check(x-1,i)) return true;
        }
        else 
        {
            if(check(x-1,1)) return true;
        }
            if(t[i]<mouth[1]) was-=t[i];
            t[i]+=mouth[x];

    }
    return false;
    
}
int main()
{
    n = read();
    for(int i=1;i<=n;i++)
    {
        c[i] = read();
        tot+=c[i];
    }
    m = read();
    for(int i=1;i<=m;i++)
    {
        mouth[i] = read();
    }
    sort(mouth+1,mouth+m+1);
    while(mouth[m]>tot) m--;
    for(int i=1;i<=m;i++)
        all[i] = all[i-1]+mouth[i];
    l = 0;
    r = m;
    while(l<=r)
    {
        was = 0;
        mid = (l+r)>>1;
        for(int i=1;i<=n;i++)
            t[i] = c[i];
        if(check(mid,1)) l = mid+1,ans = mid;
        else r = mid-1;
    }
    printf("%d\n",ans);
    return 0;
}