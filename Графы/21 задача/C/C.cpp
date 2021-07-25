#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

const int MAX_SIZE = 115;

int n, ans;
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
            if (gr[i][j]) ans++;
        }
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans/2 << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
