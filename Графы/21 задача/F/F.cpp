#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX_SIZE = 115;

int n, m;
int gr[MAX_SIZE][MAX_SIZE], used[MAX_SIZE][MAX_SIZE];

vector <pair <int,int> > ed;

void in()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        gr[a][b] = 1;
        gr[b][a] = 1;
    }
}

void out()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << gr[i][j] << " ";
        }
        cout << gr[i][n] << "\n";
    }
}

int main()
{
    in();
    out();
    return 0;
}
