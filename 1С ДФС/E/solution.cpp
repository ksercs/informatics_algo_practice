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
#include <string.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = 5000+5;

int n, ans = 1, col, pur, fl1, fl2, fl;
VEC <VEC <int> > gr;
int u[MAXN];

void dfs_R (int v)
{
    if (v == pur){
        fl = 1;
        return;
    }
    u[v] = 1;
    for (int i = 0; i < gr[v].SZ; ++i){
        int to = gr[v][i];
        int c;
        (to > 0) ? c = 1 : c = 0;
        to = abs(to);
        if (c == col && !u[to] && to <= pur){
            u[to] = 1;
            dfs_R(to);
            u[to] = 0;
        }
    }
    u[v] = 0;
}

void in()
{
    ifstream cin("input.txt");
    ios_base:: sync_with_stdio(false);
    cin >> n;
    gr.resize(n+1);
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++ j){
            char c;
            cin >> c;
            (c == 'R') ? gr[i].PB(j) : gr[i].PB(-j);
        }
}

void solution()
{
    for (int i = 1; i < n; ++i){
        for (int j = i+1; j <= n; ++j){
            pur = j;
            for (int k = 0; k < gr[i].SZ; ++k){
                int to = gr[i][k];
                (to > 0) ? col = 1 : col = 0;
                dfs_R(abs(to));
                if (fl){
                    if (col) fl1 = 1;
                    else     fl2 = 1;
                    fill(u, u+pur, 0);
                }
                fl = 0;
            }
            if (fl1 && fl2){
                ans = 0;
                break;
            }
           fl = 0;
           fl1 = 0;
           fl2 = 0;
        }
        if (!ans) break;
    }
}

void out()
{
    ofstream cout("output.txt");
    ans ? cout << "YES\n" : cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
