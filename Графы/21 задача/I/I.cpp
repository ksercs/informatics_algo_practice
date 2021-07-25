#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX_SIZE = 115;

int n;

vector <vector <int> > gr;

void in()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin.get(a);
        gr[a].push_back(i);
    }
}

void out()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < gr[i].size()-1; j++)
        {
            cout << gr[i][j] << " ";
        }
        cout << gr[i][gr[i].size()-1] << "\n";
    }
}

int main()
{
    in();
    out();
    return 0;
}
