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

const int MAXN = 10000 + 15;

int n, m, ans, cnt;
int leader[MAXN], size[MAXN];

int find_leader (int x)
{
    if (leader[x] == x) return x;
    return leader[x] = find_leader(leader[x]);
}

void union_set (int x, int y)
{
    int px = find_leader(x);
    int py = find_leader(y);
    if (px == py) return;
    if (size[px] < size[py]) swap(px, py);
    leader[py] = px;
    size[px] += size[py];
    if (size[px] == n && ans == 0) ans = -1;
}

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        leader[i] = i;
        size[i] = 1;
    }
    for (int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        union_set(a, b);
        /*for (int i = 1; i <= n; ++i)
            cout << i << ": " << leader[i] << " " << size[i] << "\n";
        cout << "\n\n";*/
        if (ans == -1) ans = i;
    }

    cout << ans << "\n";
    return 0;
}
