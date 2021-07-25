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

const int MAXN = (int)1e6+15;

int n, m;
int leader[MAXN], size[MAXN];
LL sum[MAXN];
VEC <LL> ans;

int get_leader (int x)
{
    if (leader[x] == x) return x;
    return leader[x] = get_leader(leader[x]);
}

void union_set(int x, int y, int w)
{
    int px = get_leader(x);
    int py = get_leader(y);
    if (px == py){
        sum[px] += w;
        return;
    }
    if (size[px] < size[py]) swap(px, py);
    leader[py] = px;
    size[px] += size[py];
    sum[px] += w + sum[py];
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
        int t, x, y, w;
        cin >> t;
        if (t == 1){
            cin >> x >> y >> w;
            union_set(x,y,w);
        }
        else{
            cin >> x;
            ans.PB(sum[get_leader(x)]);
        }
    }

    for (int i = 0; i < ans.SZ; ++i)
        cout << ans[i] << "\n";
    return 0;
}
