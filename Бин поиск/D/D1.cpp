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

const int MAXN = 20000 + 15;

int n, m;
VEC <int> Lans, Rans;
int mass1[MAXN], mass2[MAXN];

int Lbin_R (int x)
{
    int L = 0, R = n-1, M;
    while (R-L > 1){
        M = L + (R-L)/2;
        if (mass1[M] >= x) R = M-1;
        else               L = M+1;
        //cout << L << " " << R << "\n";
    }
    //cout << "\n"; system("PAUSE");
    if (mass1[L] == x) return L;
    if (mass1[R] == x) return R;
    if (R+1 < n && mass1[R+1] == x) return R+1;
    return -1;
}

int Rbin_R (int x)
{
    int L = 0, R = n-1, M;
    while (R-L > 1){
        M = L + (R-L)/2;
        if (mass1[M] > x) R = M-1;
        else              L = M+1;
    }
    if (mass1[R] == x)    return R;
    if (mass1[L] == x)   return L;
    if (L-1 >= 0 && mass1[L-1] == x) return L-1;
    return -1;
}

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m;
    Lans.resize(m);
    Rans.resize(m);
    for (int i = 0; i < n; ++i)
        cin >> mass1[i];
    for (int j = 0; j < m; ++j)
        cin >> mass2[j];
}

void solution()
{
    for (int i = 0; i < m; ++i){
        Lans[i] = Lbin_R (mass2[i]);
        Rans[i] = Rbin_R (mass2[i]);
    }
}

void out()
{
    ofstream cout("output.txt");
    for (int i = 0; i < m; ++i)
        (Lans[i] == -1) ? cout << "0\n" : cout << Lans[i]+1 << " " << Rans[i]+1 << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
