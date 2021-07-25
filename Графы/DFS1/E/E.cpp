#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back

const int MAX_SIZE = 115;

int n, m, ans;
int gr[MAX_SIZE][MAX_SIZE];

void DFS(int a, int b)
{
    //cout <<"   " << a << " " << b << "\n";
    gr[a][b] = 0;
    if (gr[a-1][b] == 1) DFS(a-1, b);
    if (gr[a+1][b] == 1) DFS(a+1, b);
    if (gr[a][b+1] == 1) DFS(a, b+1);
    if (gr[a][b-1] == 1) DFS(a, b-1);
}

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char s;
            cin >> s;
            if (s == '.') gr[i][j] = 0;
            else          gr[i][j] = 1;
        }
    }
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (gr[i][j] == 1)
            {
                ans++;
                gr[i][j] = 2;
                if (gr[i+1][j]) DFS(i+1, j);
                if (gr[i][j+1]) DFS(i, j+1);
            }
        }
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
