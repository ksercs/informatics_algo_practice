#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 115;

int n, st, fn;
int used[MAX_SIZE], pred[MAX_SIZE];

vector <vector <int> > gr;
vector <int> ans;

queue <int> q;

void BFS()
{
    while(!q.empty())
    {
        int v = q.front();
        for (int i = 0; i < gr[v].size(); i++)
        {
            int to = gr[v][i];
            if (!used[to])
            {
                used[to] = 1;
                pred[to] = v;
                q.push(to);
            }
        }
        q.pop();
    }
}

void get_ans(int v)
{
    int p = pred[v];
    ans.push_back(v);
    if (p) get_ans(p);
}

void in()
{
  cin >> n;
  gr.resize(n+1);
  for (int i = 1; i <= n; i++)
  {
      for (int j = 1; j <= n; j++)
      {
          int ch;
          cin >> ch;
          if (ch) gr[i].push_back(j);
      }
  }
  cin >> st >> fn;
}

void solution()
{
  used[st] = 1;
  q.push(st);
  BFS();
  if (used[fn])
  {
      get_ans(fn);
      reverse(ans.begin(), ans.end());
  }
}

void out()
{
  if (st == fn) cout <<"0\n";
  else
  {
      if (ans.size())
      {
          cout << ans.size()-1 << "\n";
          for (int i = 0; i < ans.size()-1; i++ )
          {
              cout << ans[i] << " ";
          }
          cout << ans[ans.size()-1] << "\n";
      }
      else cout << "-1\n";
  }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
