#include <iostream>
#include <algorithm>
#include <vector>

#define pb push_back
#define SZ size()

using namespace std;

const int MAXN = (int) 1e6+5;

int n, ans = MAXN, st, cnt;
int dp[MAXN];

vector <int> cub, subq;

int DFS(int ch)
{

}

void precalc()
{
    for (i = 2; i*i*i <= n; i++)
    {
        dp[i] = -1;
    }
    for (int i = 1; i*i*i <= n; i++)
    {
        cub.pb(i*i*i);
    }
}

void in()
{
    cin >> n;
}

void solution()
{
    precalc();
    ans = DFS(n);
}

void out()
{
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
