#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define pb push_back
#define SZ size()
#define mp make_pair
#define ss second
#define ff first
#define pii pair <int, int>
#define sp " "

using namespace std;

const int MAXN = (int)1e6, INF = (int)1e7;

int n, ans;
int dp[MAXN+15];
vector <int> cub;

void precalc(int fn)
{
    for (int i = 1; i*i*i <= fn; i++)
        cub.pb(i*i*i);
}

void in()
{
    cin >> n;
}

void solution()
{
    precalc(n);
    for (int i = 1; i <= n; i++){
        dp[i] = INF;
        for (int j = 0; j < cub.SZ; j++)
            if (i >= cub[j]) dp[i] = min(dp[i], dp[i-cub[j]]+1);
    }
    ans = dp[n];
    /*for (int i = 0; i <= n; i++)
        cout << dp[i] << " ";
    cout << "\n";*/
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
