#include <bits/stdc++.h>
using namespace std;

char change(char c)
{
    return c-'a'+'A';
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for (int i = 1; i <= n; i++)
    {
        string s,l;
        getline(cin, s);
        cout<<change(s[0]);
        int len = s.size();
        for(int i = 1;i<len;i++)
        {
            if(s[i]==' ')
            {
                cout<<change(s[i+1]);
            }
        }
        cout << endl;
    }
}