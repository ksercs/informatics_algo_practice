#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#define SZ size()

using namespace std;

string num1, num2;
int fl;

int comp(string s1, string s2)
{
    if (s1.SZ > s2.SZ)  return 1;
    if (s1.SZ < s2.SZ)  return -1;
    for (int i = 0; i < s1.SZ; i++)
    {
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
    }
    return 0;
}

void in()
{
    //ifstream cin("input.txt");
    cin >> num1 >> num2;
}

void solution()
{
    fl = comp(num1, num2);
}

void out()
{
    //ofstream cout("output.txt");
    if (fl == 1) cout << ">\n";
    if (fl == -1) cout << "<\n";
    if (fl == 0) cout << "=\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
