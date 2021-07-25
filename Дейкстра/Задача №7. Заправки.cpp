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

const int MAXN = 102, INF = (int)1e9;

int n, m, ans;
int d[MAXN], w[MAXN], u[MAXN], pr[MAXN];
VEC <VEC <int> > gr;
set < PII > st;
VEC <int> way;

void get_Way(int ch)
{
    way.PB(ch);
    if (pr[ch] == 0) return;
    get_Way(pr[ch]);
}

void dijkstra()
{
    PII p = (*st.begin());
    st.erase(st.begin());
    int v = p.SS;
    //cout << "V = " << v << " " << w[v] << "\n";
    u[v] = 1;
    int c = p.FF;
    for (int i = 0; i < gr[v].SZ; ++i){
        int to = gr[v][i];
        int nw = c+1;
        if (!u[to] && nw < w[to]){
            st.erase(MP(w[to],to));
            w[to] = nw;
            pr[to] = v;
            //cout << "TO = " << to << " " << w[to] << "\n";
            st.insert(MP(nw, to));
        }
    }
    if (st.SZ > 0) dijkstra();
}

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    gr.resize(n+1);
    cin >> m;
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        gr[a].PB(b);
        gr[b].PB(a);
    }
}

void solution()
{
    w[1] = 0;
    st.insert(MP(0,1));
    for (int i = 2; i <= n; ++i){
        st.insert(MP(INF, i));
        w[i] = INF;
    }
    dijkstra();
    if (w[n] == INF) return;
    get_Way(n);
    reverse(way.begin(), way.end());
    int ind = 0;
    while (ind < way.SZ){
        ans += d[way[ind]];
        ind += d[way[ind]];
    }
}

void out()
{
    ofstream cout("output.txt");
    if (w[n] == INF) cout << "-1\n";
    else             cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
