#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n;
int used[10];

string str, s;

vector <int> el;
vector <string> ans;

void out()
{
     ofstream cout ("output.txt");
     for (int i = 0; i < ans.size(); i++)
     {
         for (int j = 0; j < ans[i].size(); j++)
         {
             cout << s[(int)(ans[i][j]-'0'-1)];
         }
         cout << "\n";
     }
}

void dfs_R(int ind)
{
    if (ind == n)
    {
        ans.push_back(str);
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (used[i] == 0)
            {
                used[i] = 1;
                str[ind] = i+'0';
                dfs_R(ind+1);
                used[i] = 0;
            }
        }
    }
}

void in()
{
    ifstream cin ("input.txt");
    cin >> s;
    n = s.size();
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        el.push_back(i);
        str+= ' ';
    }
    dfs_R(0);
}

int main()
{
    in();
    solution();
    out();
return 0;
}
