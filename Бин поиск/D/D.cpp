#include <iostream>
#include <algorithm>
#include <vector>

#define sp " "

using namespace std;

int n, k;
vector <int> num, mass;
vector<int>::iterator low,up;

void in()
{
  cin >> n >> k;
  mass.resize(n);
  num.resize(k);
  for (int i = 0; i < n; i++)
   {
     cin >> mass[i];
   }
  for (int i = 0; i < k; i++)
   {
     cin >> num[i];
   }
}

void out()
{
    for (int i = 0; i < k; i++)
    {
      if ( !binary_search(mass.begin(), mass.end(), num[i]) ) cout << "0\n";
      else
      {
          low = lower_bound(mass.begin(), mass.end(), num[i]);
          up = upper_bound (mass.begin(), mass.end(), num[i]);
          cout << (low- mass.begin())+1 << sp;
          cout << (up - mass.begin()) << endl;
      }
    }
}

int main()
{
  in();
  out();
}
