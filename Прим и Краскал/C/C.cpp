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

int n, a, b, w;
int mass[MAXN];

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> mass[i];
    cin >> a >> b;
}

void solution()
{
    w = mass[a];
    for (int i = 1; i <= n; ++i)
        if (mass[i] == w) mass[i] = mass[b];
}

void out()
{
    ofstream cout("output.txt");
    for (int i = 1; i < n; ++i)
        cout << mass[i] << " ";
    cout << mass[n] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
