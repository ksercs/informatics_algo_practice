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

int n, used, ed;
int u[MAXN];
VEC < VEC <int> > gr;

void DFS(int v)
{
    u[v] = 1;
    used--;
    for (int i = 0; i < gr[v].SZ; ++i){
        int to = gr[v][i];
        if (!u[to]) DFS(to);
    }
}

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    gr.resize(n+1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            int a;
            cin >> a;
            if (a) {
                gr[i].PB(j);
                ed++;
            }
        }
}

void solution()
{
    used = n;
    ed /= 2;
    DFS(1);
}

void out()
{
    ofstream cout("output.txt");
    if (!used && ed == n-1) cout << "YES\n";
    else       cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
