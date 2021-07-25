#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX_SIZE = 115;

int n;
int gr[MAX_SIZE][MAX_SIZE], used[MAX_SIZE][MAX_SIZE];

vector <pair <int,int> > ans;

void in()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> gr[i][j];
            if (gr[i][j]) ans.push_back(make_pair(i,j));
        }
    }
}

void out()
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " <<ans[i].second << "\n";
    }
}

int main()
{
    in();
    out();
    return 0;
}
