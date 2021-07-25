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

const int MAXN = 1000 + 15;

int n, m;
int d[MAXN][MAXN];
int s1[MAXN], s2[MAXN];

VEC <int> ans;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; i++)
            cin >> s1[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
            cin >> s2[i];
}

void solution()
{
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            s1[i]==s2[j] ? d[i][j]=d[i-1][j-1]+1 : d[i][j]= max(d[i-1][j], d[i][j-1]);
        }
    }
    int i = n, j = m;
    while (d[i][j] != 0){
        while (d[i][j-1] == d[i][j]) j--;
        while (d[i-1][j] == d[i][j]) i--;
        ans.PB(s1[i]);
        i--;j--;
    }
    reverse(ans.begin(), ans.end());
}

void out()
{
    ofstream cout("output.txt");
    if (ans.SZ > 0){
        for (int i = 0 ; i < ans.SZ-1; i++)
                cout << ans[i] << " ";
        cout << ans[ans.SZ-1];
    }
    cout << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
