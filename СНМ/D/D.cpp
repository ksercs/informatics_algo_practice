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

const int MAXN = 50000 + 15, MAXK = 150000 + 15;

int n, m, q;
int leader[MAXN], size[MAXN], t[MAXK];
VEC <int> ans;
VEC < PII > ed, com;

int getLeader (int x)
{
    if (leader[x] == x) return x;
    return leader[x] = getLeader(leader[x]);
}

void unionSet (int x, int y)
{
    int px = getLeader(x);
    int py = getLeader(y);
    if (px == py) return;
    if (size[px] < size[py]) swap(px, py);
    leader[py] = px;
    size[px] += size[py];
}

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m >> q;
    ed.resize(m+1);
    for (int i = 1; i <= m; ++i)
        cin >> ed[i].FF >> ed[i].SS;
    com.resize(q+1);
    for (int i = 1; i <= q; ++i){
        string str;
        int a, b;
        cin >> str >> a >> b;
        //cout << str << " " << a << " " << b << "\n";
        if (str == "cut") t[i] = 1;
        com[i] = MP(a, b);
    }
}

void solution()
{
    for (int i = 1; i <= n; ++i){
        leader[i] = i;
        size[i] = 1;
    }
    for (int i = q; i >= 1; --i){
        //cout << t[i] << " " << com[i].FF << " " << com[i].SS << "\n";
        if (t[i])
            unionSet(com[i].FF, com[i].SS);
        else if (getLeader(com[i].FF) == getLeader(com[i].SS)) ans.PB(1);
             else                                              ans.PB(0);
    }
}

void out()
{
    ofstream cout("output.txt");
    for (int i = ans.SZ-1; i >= 0; --i)
        (ans[i]) ? cout << "YES\n" : cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
