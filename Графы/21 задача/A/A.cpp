#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

const int MAX_SIZE = 115;

int n, answer = 1;
int gr[MAX_SIZE][MAX_SIZE];

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> gr[i][j];
        }
    }
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (gr[i][j] != gr[j][i] || gr[i][i] != 0) answer = 0;
        }
    }
}

void out()
{
    ofstream cout("output.txt");
    if (answer) cout <<"YES\n";
    else        cout <<"NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
