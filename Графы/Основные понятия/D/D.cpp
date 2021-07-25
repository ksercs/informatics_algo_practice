#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 115;

int n, sum=1000000000, ans, s1, s2, s3;

int gr[MAX_SIZE][MAX_SIZE];

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >>gr[i][j];
        }
    }
}

void solution()
{
  for (int i = 1; i <= n; i++)
  {
      for (int j = 1; j <= n; j++)
      {
          if (i != j)
          {
             ans += gr[i][j];
             for (int g = 1; g <= n; g++)
             {
                if (g != i && g != j)
                {
                  ans += gr[j][g] + gr[g][i];
                  if (sum > ans)
                  {
                      sum = ans;
                      s1 = i;
                      s2 = j;
                      s3 = g;
                  }
                  ans -= (gr[j][g] + gr[g][i]);
                }
             }
             ans -= gr[i][j];
          }
      }
  }
}

void out()
{
    ofstream cout("output.txt");
    cout << s1 << " " << s2 << " " <<s3 << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
