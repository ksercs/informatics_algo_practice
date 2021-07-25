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

int n, k, b, m, a;
VEC <LL> v, dp, ans;

void in()
{
    ifstream cin("input.txt");
    cin >> n >> a >> k >> b >> m;
    v.resize(n);
    v[0] = a;
    for (int i = 1; i < n; i++)
    {
        v[i] =(k*v[i-1]+b)%m;
    }
}

void solution()
{
    dp.PB(v[0]);
    for (int i = 0; i < n; i++)
    {
        int ind = lower_bound(dp.begin(), dp.end(), v[i])-dp.begin();
        if (ind == (int)dp.SZ)  {dp.PB(v[i]); ans.PB(dp[ind-1]);}
        else                dp[ind] = v[i];
    }
    ans.PB(dp[dp.SZ-1]);
}

void out()
{
    ofstream cout("output.txt");
   // cout << ans.SZ << "\n";
    for (int i = 0; i < ans.SZ-1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[ans.SZ-1] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}

