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

const int MAXN = 17;

int n, m, k, fl, nt;
int used[MAXN], num[MAXN];
PII mass[MAXN];

VEC <VEC <int> > gr;
string ans, str;
set <string> st;

int gcd_R(int a, int b)
{
    (a && b) ? gcd_R(b, a%b) : (a|b);
}

void dfs_R(int ind)
{
    //cout << ind << " " << str << "\n";
     if (fl) return;
    if (nt == n){
        st.insert(str);
        //cout << "\nANS = " << str << "\n\n";
        if (st.SZ == m){
           // cout << "EXIT\n";
            ans = str;
            fl = 1;
            //out();
        }
    }
    else
        for (int i = 0; i < gr[ind].SZ; ++i){
            int to = gr[ind][i];
            if (!used[to])
            {
                used[to] = 1;
                str[nt] = (to+'0');
                //cout << "TO: " << str << "\n";
                nt++;
                dfs_R(to);
                if (fl) return;
                nt--;
                used[to] = 0;
            }
        }
}

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i){
        cin >> mass[i].FF;
        num[i] = mass[i].FF;
        mass[i].SS = i;
        str +=' ';
    }
}

void solution()
{
    gr.resize(n+1);
    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j)
            if (gcd_R(mass[i].FF, mass[j].FF) >= k){
                gr[i].PB(j);
                gr[j].PB(i);
            }
    sort(mass, mass+n);
    for (int i = 0; i < n; ++i)
        if (!fl){
            int c = mass[i].SS;
            str[0] = (c+'0');
            nt = 1;
            used[c] = 1;
            dfs_R(c);
            used[c] = 0;
        }
}

void out()
{
    ofstream cout("output.txt");
    //cout << "OUT = " << ans << "\n";
    cout << fl << " " << ans << "\n";
    if (!fl){
        cout << "-1\n";
        return;
    }
    //cout << "OUT = " << ans << "\n";
    for (int i = 0; i < n-1; ++i){
        cout << num[(ans[i]-'0')] << " ";
        //cout << (ans[i]-'0') << "\n";
    }
    cout << num[(ans[n-1]-'0')] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
