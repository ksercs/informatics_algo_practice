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

int n, ans;
int dp[35];

int get_ans(int h)
{
    //cout << h << endl; system("PAUSE");
    if (h < 0) return 0;
    if (dp[h] != 0) return dp[h];
    else
    {
        dp[h] = (get_ans(h-1) + get_ans(h-2) + get_ans(h-3));
        return dp[h];
    }
}

void in()
{
  //ifstream cin("input.txt");
    cin >> n;
}

void solution()
{
    dp[0]=1;
    ans = get_ans(n);
}

void out()
{
  // ofstream cout("output.txt");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
