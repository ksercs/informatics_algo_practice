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

int ans, n;

VEC < PII > v;

bool comp(PII p1, PII p2)
{
    if (p1.FF == p2.FF) return p1.SS > p2.SS;
    else                return p1.FF < p2.FF;
}

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.PB(MP(a, 1));
        v.PB(MP(b, -1));
    }
}

void solution()
{
    sort(v.begin(), v.end(), comp);
    /*for (int i=0; i < v.SZ; i++)
    {
        cout << v[i].FF <<  " " << v[i].SS << endl;
    }*/
    int b = 0;
    for (int i = 0; i < v.SZ-1; i++)
    {
        b += v[i].SS;
        if (b > 0) ans += v[i+1].FF-v[i].FF;
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
