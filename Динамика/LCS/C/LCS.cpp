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

const int MAXN = 1000 + 15;

int n, m;
int d[MAXN][MAXN];

string s1, s2;

void in()
{
    ifstream cin("input.txt");
    cin >> s1 >> s2;
    s1 = s1;
    s2 = s2;
    n = s1.SZ;
    m = s2.SZ;
}

void solution()
{
    for (int i = 1; i <= m; i++) d[0][i] = i;
    for (int i = 1; i <= n; i++) d[i][0] = i;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            d[i][j] = min(min(d[i][j-1]+1, d[i-1][j]+1), d[i-1][j-1] + (int)(s1[i-1] != s2[j-1]));
        }
    }
    /*for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++)
            cout << d[i][j] << " ";
        cout << "\n";
    }*/
}

void out()
{
    ofstream cout("output.txt");
    cout << d[n][m] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
