#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector <int> num, mass;

void in()
{
  cin >> n >> k;
  mass.resize(n+1);
  num.resize(k+1);
  for (int i = 1; i <= n; i++)
   {
     cin >> mass[i];
   }
  for (int i = 1; i <= k; i++)
   {
     cin >> num[i];
   }
}

void out()
{
    for (int i = 1; i <= k; i++)
    {
      if ( binary_search(mass.begin()+1, mass.end(), num[i]) ) cout << "YES\n";
      else                                                         cout << "NO\n";
    }
}

int main()
{
  in();
  out();
}
