#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 115;

int n, m;

vector <set <int> > gr;

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m;
    gr.resize(n+1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        gr[a].insert(b);
        gr[b].insert(a);
    }
}

void out()
{
    ofstream cout("output.txt");
        for (int i = 1; i < n; i++)
        {
            cout << gr[i].size() << " ";
        }
        cout << gr[n].size() << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
