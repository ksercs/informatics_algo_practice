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

const int MAXN = (int)1e6+20, INF = (int)1e7;

int n, x;
int dp[MAXN];
VEC <int> v, ans;

bool comp(int a, int b)
{
    return a > b;
}

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> x;
}

void solution()
{
    sort(v.begin(), v.end(), comp);
    for (int i = 1; i <= x; i++){
        dp[i] = INF;
        for (int j = 0; j < v.SZ; j++)
            if (i >= v[j]) dp[i] = min(dp[i], dp[i-v[j]]+1);
    }
    //cout << dp[x] << "\n";
    //for (int i = 0; i <= x; i++)
   //     cout << dp[i] << " ";
    if (dp[x] != INF)
        while (x  > 0){
            //cout << x << "\n";
            for (int i = 0; i < v.SZ; i++)
                if (x-v[i] >= 0 && x-1 >= 0 && dp[x-v[i]] == dp[x]-1){
                    ans.PB(v[i]);
                    x -= v[i];
                    break;
                }
        }
}

void out()
{
    ofstream cout("output.txt");
    if (dp[x] == INF) cout << "No solution\n";
    else{
        for (int i = 0; i < ans.SZ-1; i++)
            cout << ans[i] << " ";
        cout << ans[ans.SZ-1] << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
