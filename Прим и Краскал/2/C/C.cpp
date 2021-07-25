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

const int MAXN = 55, INF = int(1e9);

int n, ans, m, ind=1;
int inTree[MAXN], w[MAXN], pr[MAXN];
VEC <VEC < PII > > gr;
set < PII > st;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    gr.resize(n+1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            int c;
            cin >> c;
            if (i == j) continue;
            gr[i].PB(MP(j,c));
            gr[j].PB(MP(i,c));
        }
}

void solution()
{
    for (int i = 1; i <= n; ++i){
        w[i] = INF;
        st.insert(MP(w[i], i));
    }
    w[ind] = 0;
    st.erase(MP(INF, ind));
    st.insert(MP(0,ind));
    for (int i = 0; i < n; ++i){
        PII p = (*st.begin());
        int v = p.SS;
        //cout << v << "\n";
        ans += p.FF;
        inTree[v] = 1;
        st.erase(st.begin());
        for (int j = 0; j < gr[v].SZ; ++j){
            int to = gr[v][j].FF,
                cost = gr[v][j].SS;
            if (w[to] > cost && !inTree[to]){
                st.erase(MP(w[to], to));
                w[to] = cost;
                pr[to] = v;
                st.insert(MP(w[to], to));
            }
        }
    }
    //for (int i = 1; i <= n; ++i)
    //    cout << i << " " << pr[i] << " " << w[i] << "\n";
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
