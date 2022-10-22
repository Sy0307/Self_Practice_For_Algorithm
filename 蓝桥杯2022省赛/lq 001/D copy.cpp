#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
const int N=61;
const int M=1055;
int n,m,tot,waste,mou[M],all[M],c[N],t[N],ans,l,r,mid;
inline int read()
{
    char ch=getchar();int num=0;bool flag=false;
    while(ch<'0'||ch>'9'){if(ch=='-')flag=true;ch=getchar();}
    while(ch>='0'&&ch<='9'){num=num*10+ch-'0';ch=getchar();}
    return flag?-num:num;
}
inline bool dfs(int num,int sta)
{
    if(!num)return 1;
    if(tot-waste<all[mid])return 0;
    for(int i=sta;i<=n;++i)
    if(t[i]>=mou[num]){
        t[i]-=mou[num];
        if(t[i]<mou[1])waste+=t[i];
        if(mou[num]==mou[num-1]){
            if(dfs(num-1,i))return 1;}
        else {
            if(dfs(num-1,1))return 1;}
        if(t[i]<mou[1])waste-=t[i];
        t[i]+=mou[num];
    }
    return 0;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        c[i]=read();
        tot+=c[i];
    }
    m=read();
    for(int i=1;i<=m;++i)mou[i]=read();
    sort(mou+1,mou+m+1);
    while(mou[m]>tot)m--;
    for(int i=1;i<=m;++i)   
        all[i]=all[i-1]+mou[i];
    l=0,r=m;
    while(l<=r){
        waste=0;
        mid=(l+r)>>1;
        for(int i=1;i<=n;++i)t[i]=c[i];
        if(dfs(mid,1))l=mid+1,ans=mid;
        else r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}