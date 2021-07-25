#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_SIZE = 26;

int n, sx, sy, fx, fy;
int used[MAX_SIZE][MAX_SIZE];
int dx[]={2, 1, -1, 2, -2, 1, -1, -2},
    dy[]={1, 2, 2, -1, 1, -2, -2, -1};

pair <int, int> pred[MAX_SIZE][MAX_SIZE];
queue <pair <int, int> > q;
vector <pair <int, int> > ans;

void get_ans(int x, int y)
{
    int px = pred[x][y].first, py = pred[x][y].second;
    ans.push_back(make_pair(x, y));
    if (pred[px][py].first) get_ans(px, py);
}

void BFS()
{
    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        if (x == fx && y == fy) break;
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (!used[nx][ny])
            {
                pred[nx][ny] = make_pair(x,y);
                used[nx][ny] = 1;
                q.push(make_pair(nx,ny));
            }
        }
        q.pop();
    }
}

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    cin >> sx >> sy;
    cin >> fx >> fy;
}

void solution()
{
  for (int i = 0; i <= n+3; i++)
  {
      for (int j = 0; j <= n+3; j++)
      {
          used[i][j] = 1;
      }
  }
  for (int i = 2; i <= n+1; i++)
  {
      for (int j = 2; j <= n+1; j++)
      {
          used[i][j] = 0;
      }
  }
  sx++; fx++; sy++; fy++;
  q.push(make_pair(sx,sy));
  used[sx][sy] = 1;
  BFS();
  if (used[fx][fy])get_ans(fx, fy);
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans.size() << "\n";
    cout << sx-1 << " " << sy-1 << "\n";
    for (int i = ans.size()-1; i >= 0; i--)
    {
        cout << ans[i].first-1 << " " << ans[i].second-1 << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
