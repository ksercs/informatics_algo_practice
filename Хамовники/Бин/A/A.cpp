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

int n, x, y, ans, L = 1, R;

void bin()
{
    while(R-L > 1){
        int M = (L+(R-L)/2);
        //cout << L << " " << R << " " << M << "\n";
        if (M/x + M/y >= n) R = M;
        if (M/x + M/y < n) L = M+1;
    }
    if (L/x + L/y >= n) ans +=L;
    else ans += R;
}

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> x >> y;
}

void solution()
{
    ans += min(x,y);
    if (n == 1) return;
    n -= 1;
    R = n*min(x,y)+1;
    bin();
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
