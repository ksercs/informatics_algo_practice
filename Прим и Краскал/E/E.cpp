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
#define PII pair <LL,LL>
#define LL long long

using namespace std;

const int MAXN = 2*(int)1e4+5, INF = int(1e9)+15;

LL n, m, ans;
LL w[MAXN], p[MAXN], inTree[MAXN];
VEC < VEC < PII > > gr;
set < PII > st;

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m;
    gr.resize(n+1);
    for (int i = 0; i < m; ++i){
        LL a, b, c;
        cin >> a >> b >> c;
        if (a == b) continue;
        gr[a].PB(MP(b, c));
        gr[b].PB(MP(a, c));
    }
}

void solution()
{
    st.insert(MP(0, 1));
    for (int i = 2; i <= n; ++i){
        w[i] = INF;
        st.insert(MP(w[i], i));
        p[i] = -1;
    }
    for (int i = 0; i < n; ++i){
        int v = (*st.begin()).SS;
        inTree[v] = 1;
        ans += (*st.begin()).FF;
        st.erase(st.begin());
        //cout << v << "\n";
        for (int j = 0; j < gr[v].SZ; ++j) {
            int to = gr[v][j].FF,
                cost = gr[v][j].SS;
            if (cost < w[to] && !inTree[to] ) {
                st.erase(MP(w[to], to));
                w[to] = cost;
                p[to] = v;
                st.insert(MP (w[to], to));
            }
        }
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
