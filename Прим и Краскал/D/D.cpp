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

const int MAXN = 102, INF = 1000+15;

int n, m = INF;
int mass[MAXN], gr[MAXN][MAXN];
PII ans;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> gr[i][j];
    for (int i = 1; i <= n; ++i)
        cin >> mass[i];
}

void solution()
{
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j)
            if (gr[i][j] < m)
                if (mass[i] == 0 && mass[j] == 1){
                    m = gr[i][j];
                    ans = MP(i,j);
                }
                else if (mass[i] == 1 && mass[j] == 0){
                    m = gr[i][j];
                    ans = MP(j,i);
                }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans.FF << " " << ans.SS << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
