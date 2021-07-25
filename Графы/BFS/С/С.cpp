#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX_SIZE = 100+15;

int n, m, answer, ax, ay, us, fl;
int tabl[MAX_SIZE][MAX_SIZE], ans[MAX_SIZE][MAX_SIZE], used[MAX_SIZE][MAX_SIZE],
    dx[] = {-1, 1, 0, 0},
    dy[] = {0, 0, -1, 1};

vector <pair <int, int> > vec;
queue <pair <int,int> > q;

void BFS()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        //cout << x << " " << y << "\n"; system("PAUSE");
        used[x][y] = us;
        for (int g = 0; g < 4; g++)
        {
            int tx = x+dx[g];
            int ty = y+dy[g];
            //cout << "      " << tx << " " << ty << "\n";
            if (used[tx][ty] != us && tabl[tx][ty] != -1)
            {
                q.push(make_pair(tx, ty));
                used[tx][ty] = us;
                ans[tx][ty] = min(ans[tx][ty], ans[x][y]+1);
            }
        }
        q.pop();
    }
}

void in()
{
   ifstream cin("input.txt");
   cin >> n >> m;
   for (int i = 0; i <= n+1; i++)
   {
       for (int j = 0; j <= m+1; j++)
       {
           tabl[i][j] = -1;
           ans[i][j] = 1000000;
       }
   }
   for (int i = 1; i <= n; i++)
   {
       for (int j = 1; j <= m; j++)
       {
           cin >> tabl[i][j];
           if (tabl[i][j])
           {
               ans[i][j] = 0;
               vec.push_back(make_pair(i,j));
           }
       }
   }
}

void solution()
{
  for (int i = 0; i < vec.size(); i++)
  {
      us++;
      int xx = vec[i].first;
      int yy = vec[i].second;
      q.push(make_pair(xx, yy));
      used[xx][yy] = us;
      BFS();
  }
}

void out()
{
    ofstream cout("output.txt");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << ans[i][m] << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
