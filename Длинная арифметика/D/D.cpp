#include <iostream>
#include <fstream>
#include <string>

#define SZ size()

using namespace std;

string num1, num2, raz, str;
int fl;

string reverse( string s)
{
    int n = (int)s.SZ;
    for (int i=0; i < n/2; i++)
       swap(s[i], s[n-i-1]);
    return s;
}

void mn(int ind, int z)
{
    int z1 = (raz[ind]-'0');
    if (z1-z >= 0)
    {
        if (!fl)    raz[ind] = (char)(z1-z+'0');
        else
        {
            if (z1-z-1 >= 0) {raz[ind] = (char)(z1-z-1+'0'); fl = 0;}
            else              raz[ind] = (char)(z1-z+9+'0');
        }
    }
    else
    {
        if (fl) raz[ind] = (char)(z1-z+9+'0');
        else    {raz[ind] = (char)(z1-z+10+'0'); fl = 1;}
    }
    //cout << ind << " " << z1 << " " << z <<  " " << raz[ind] << endl;
    ind++;
    if (ind != raz.SZ) mn(ind, str[ind]-'0');
}

void subtr(string s1, string s2)
{
    s1 = reverse(s1);
    raz = s1;
    s2 = reverse(s2);
    for (int i = s2.SZ; i < s1.SZ; i++)
    {
        s2 += '0';
    }
    str = s2;
    mn(0, str[0]-'0');
}

void in()
{
    //ifstream cin("input.txt");
    cin >> num1 >> num2;
}

void solution()
{
    subtr(num1, num2);
    raz = reverse(raz);
    int smb = raz[0];
    while (smb == '0')
    {
        raz.erase(0,1);
        smb = raz[0];
    }
}

void out()
{
    //ofstream cout("output.txt");
    if (raz.SZ == 0)cout << "0" << endl;
    else            cout << raz << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
