#include<bits/stdc++.h>
using namespace std;

double a,b,c,d;
double res(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>a>>b>>c>>d;
    int cnt = 0;
    for(double i=-100;i<=100;i+=0.001)
    {
        double j = i+0.001;
        if(res(i)*res(j)<0)
        {
            printf("%0.2f ",i);
            cnt++;
        }
        if(cnt==3) return 0;
    }
    return 0;
}