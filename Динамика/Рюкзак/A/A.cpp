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

const int MAXN = (int) 1e6+5;

int n, ans = MAXN, st, cnt=-1;
int used[MAXN];

vector <int> cub;

pii BS_R(int L, int R, int X)
{
    //cout << "BS: " << L << sp << R << sp << X << endl; system("PAUSE");
    if (L > R)  return mp(L-1, 0);
    int M = L+(R-L)/2;
    //cout <<L <<" " <<R << " " << M <<"\n";
    if (cub[M] == X)   return mp(M,1);
    if (cub[M] < X)    return BS_R(M+1, R, X);
    if (cub[M] > X)    return BS_R(L, M-1, X);
}

void DFS(int ch)
{
    cnt++;
    cout <<"CH   CNT:   " << ch << sp << cnt << endl; system("PAUSE");
    if (cnt > ans) {/*cout <<"RETURN\n";*/ cnt--; return;}
    //cout << ch << endl;
   if (ch == n)  ans = cnt;
   else
   {
       int i = st;
       while (i > 0)
       {
            i = BS_R(0, i, n-ch).ff;
            //cout << "I:  " << i << endl;
           // cout << x << " ";
          //  cout << cub[x] << "\n"; //system("PAUSE");
          if (i == 0) break;
          if (used[ch+cub[i]] > cnt+1)
          {
              used[ch+cub[i]] = cnt+1;
              ch += cub[i];
              DFS(ch);
              ch -= cub[i];
          }
          else i--;
       }
       if (!i && cnt+n-ch < ans)  ans = cnt+n-ch;
   }
   cnt--;
}

void precalc(int fn)
{
    for (int i = 1; i*i*i <= fn; i++)
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
    for (int i = 1; i <= 1000000; i++)
    {
        used[i] = MAXN;
    }
    precalc(n);
    st = cub.SZ - 1;
    DFS(0);
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
