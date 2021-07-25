#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <queue>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = 102;

int n, m;
int u[MAXN];
VEC < VEC <int> > gr;
VEC < PII > ans;
queue <int> q;

void BFS()
{
    while (!q.empty()){
        int v = q.front();
        for (int i = 0; i < gr[v].SZ; ++i){
            int to = gr[v][i];
            if (!u[to]){
                q.push(to);
                u[to] = 1;
                ans.PB(MP(v,to));
            }
        }
        q.pop();
    }
}

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m;
    gr.resize(n+1);
    for (int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        gr[a].PB(b);
        gr[b].PB(a);
    }
}

void solution()
{
    q.push(1);
    u[1] = 1;
    BFS();
}

void out()
{
    ofstream cout("output.txt");
    for (int i = 0; i < ans.SZ; ++i)
        cout << ans[i].FF << " " << ans[i].SS << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
