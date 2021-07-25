#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back

const int MAX_SIZE = 115;

int n, m, fl = 2, answer = 1;

int used[MAX_SIZE];

vector <vector <int> > gr;
vector <int> team;

void DFS(int v)
{
    if (fl == 2) fl = 1;
    else fl = 2;
    used[v] = fl;
    for (int i = 0; i < gr[v].size(); i++)
    {
        int to = gr[v][i];
        if (used[to] == fl) answer = 0;
        else
        {
            if (!used[to]) DFS(to);
        }
    }
    if (fl == 2) fl = 1;
    else fl = 2;
}

void in()
{
    //ifstream cin("D.in");
    cin >> n >> m;
    gr.resize(n+1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        gr[a].pb(b);
        gr[b].pb(a);
    }
}

void solution()
{
  for (int i = 1; i <= n; i++)
  {
      if (!used[i]) DFS(i);
  }
  if (answer)
  {
      for(int i = 1; i<= n; i++)
      {
          if (used[i] == 1) team.pb(i);
      }
  }
}

void out()
{
    //ofstream cout("D.out");
    if (answer)
    {
        cout <<"YES\n";
        for (int i = 0; i < max(0, int(team.size()-1)); i++)
        {
            cout << team[i] << " ";
        }
        cout << team[team.size()-1] << "\n";
    }
    else cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
