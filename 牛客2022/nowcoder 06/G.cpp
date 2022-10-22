#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int row;
int col;
char mat[1000][1000];
void print(char mat[1000][1000])
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
    // cout << "row = " << row << endl;
    // cout << "col = " << col << endl;
}
void solve()
{
    int n;
    cin >> n;
    row = 4 * n + 5;
    col = 13 * n + 19;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = '.';
        }
    }
    for (int i = 1; i <= row; i++)
    {
        mat[i][1] = '*';
        mat[i][col] = '*';
    }
    for (int j = 1; j <= col; j++)
    {
        mat[1][j] = '*';
        mat[row][j] = '*';
    }

    // N
    
    for (int i = n; i < 2 * n + 3 + n; i++)
    {
        mat[i + 2][n + 3] = '@';
    }

    for (int i = 0; i < 2 * n + 3; i++)
    {
        mat[i + n + 2][n + 3 + i] = '@';
    }

    for (int i = n; i < 2 * n + 3 + n; i++)
    {
        mat[i + 2][n + 2 + 2 * n + 3] = '@';
    }

    int k = 7 + 4 * n;

    // F

    for (int i = n; i < 2 * n + 3 + n; i++)
    {
        mat[i + 2][k] = '@';
    }

    for (int i = 0; i < 2 * n + 3; i++)
    {
        mat[n + 2][k + i] = '@';
    }
    for (int i = 0; i < 2 * n + 3; i++)
    {
        mat[n * 2 + 3][k + i] = '@';
    }

    // L
    k += 2 * n + 3 + n + 1;

    for (int i = n; i < 2 * n + 3 + n; i++)
    {
        mat[i + 2][k] = '@';
    }

    for (int i = 0; i < 2 * n + 3; i++)
    {
        mat[n * 3 + 4][k + i] = '@';
    }

    // S
    k += 2 * n + 3 + n + 1;

    // for (int i = n; i < 2 * n + 3 + n; i++)
    // {
    //     mat[i + 2][k] = '@';
    // }
    for (int i = 0; i < 2 * n + 3; i++)
    {
        mat[n * 2 + 3][k + i] = '@';
    }

    for (int i = 0; i < 2 * n + 3; i++)
    {
        mat[n * 1 + 2][k + i] = '@';
    }

    for (int i = 0; i < 2 * n + 3; i++)
    {
        mat[n * 3 + 4][k + i] = '@';
    }



    for (int i = n; i < n + 2 + n; i++)
    {
        mat[i + 2][k] = '@';
    }

    for (int i = n; i < n + 2 + n; i++)
    {
        mat[i+n+3][k+2*n+2] = '@';
    }

    print(mat);
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}