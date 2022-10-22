#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n, ans = 1;
    cin >> n;
    for (long long i = 2; i <= n; i++)
    {
        long long ii = i - 1;
        for (long long j = 1; j <= 10; j++)
        {
            if ((long long)pow(10, j) >= n)
            {
                ans += j;
             //   cout<<i<<": "<<j<<endl;
                break;
            }
            long long s1 = (ii * (long long)pow(10, j)) % n;
            long long s2 = (i * (long long)pow(10, j) - 1) % n;
        //    if(s1==s2) cout<<"YES"<<endl;
            if (s1 < s2)
            {
                if (s1 <= i && i <= s2)
                {
                    ans += j;
                  //  cout<<i<<": "<<j<<endl;
                    break;
                }
            }
            if (s1 > s2)
            {
                if (i >= s1 || i <= s2)
                {
                    ans += j;
                 //   cout<<i<<": "<<j<<endl;
                    break;
                }
            }
        }
    }
    cout << ans<<endl;;
}