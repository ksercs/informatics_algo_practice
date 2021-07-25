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

int n, k;
VEC <string> ans;

void DFS_R (int ind, string str)
{
    if (ind == n){
        ans.PB(str);
        return;
    }
    for (int i = 0; i < k; ++i){
        str[ind] = char(i + '0');
        DFS_R(ind+1, str);
    }
}

void in()
{
    ifstream cin("input.txt");
    cin >> n >> k;
}

void solution()
{
    string str;
    for (int i = 0; i < n; ++i)
        str += '0';
    DFS_R(0, str);
}

void out()
{
    ofstream cout("output.txt");
    for (int i = 0; i < ans.SZ; ++i)
        cout << ans[i] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
