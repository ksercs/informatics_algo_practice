#include <iostream>
#include <algorithm>
#include <utility>

#define mp make_pair
#define ss second
#define ff first
#define pii pair <int, int>

using namespace std;

const int MAXSZ = (int)1e5+5;

int n, k;
int num[MAXSZ], mass[MAXSZ], ans[MAXSZ];

pii BS(int L, int R, int X)
{
    while(  !(L > R) )
    {
        int M = L+(R-L)/2;
        //cout <<L <<" " <<R <<"\n";
        if (mass[M] == X)  	return mp(M, 1);
        if (mass[M] < X) 	L = M+1;
        if (mass[M] > X) 	R = M-1;
    }
    return mp(L, 0);
}

void in()
{
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
   {
     cin >> mass[i];
   }
  for (int i = 1; i <= k; i++)
   {
     cin >> num[i];
   }
}

void solution()
{
    for (int i = 1; i <= k; i++)
    {
      int ch = num[i];
      pii pa = BS(1, n, ch);
      if (pa.ss == 1 || pa.ff == 1) ans[i] = mass[pa.ff];
      else
      {
        if (pa.ff == n+1) ans[i] = mass[n];
        if ( abs(mass[pa.ff]-ch) < abs(mass[pa.ff-1]-ch) ) ans[i] = mass[pa.ff];
        else                                               ans[i] = mass[pa.ff-1];
      }
    }

}

void out()
{
    for (int i = 1; i <= k; i++)
    {
      cout << ans[i] << endl; //system("PAUSE");
    }
}

int main()
{
  in();
  solution();
  out();
}
