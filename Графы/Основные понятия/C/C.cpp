#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX_COUNT = 115;

int n, ans;

int used[MAX_COUNT][MAX_COUNT];
int col[MAX_COUNT];

vector <pair <int, int> > ed;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ch;
            cin >> ch;
            if (ch)
            {
                if (!used[i][j])
                {
                    used[i][j] = 1;
                    used[j][i] = 1;
                    ed.push_back(make_pair(i, j));
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> col[i];
    }
}

void solution()
{
    for (int i = 0; i < ed.size(); i++)
    {
        int st, fn;
        st = ed[i].first;
        fn = ed[i].second;
        if (col[st]!=col[fn]) ans++;
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
