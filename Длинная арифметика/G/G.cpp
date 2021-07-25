#include <iostream>
#include <fstream>
#include <string>

#define SZ size()

using namespace std;

string num1, s1, s2, s3, rez;
int st, dop, fl, n;

string reverse( string s)
{
    int n = (int)s.SZ;
    for (int i=0; i < n/2; i++)
       swap(s[i], s[n-i-1]);
    return s;
}

void ymn (int mn, int ind, int z)
{
    //cout << mn << " " << ind << " " << z << endl;
    int zn = mn*z;
    //cout << "ZN = " << zn << endl;
    if (rez.SZ >= ind+1) rez[ind] = char(rez[ind]-'0' + zn%10 + '0');
    else                 rez += char(zn%10 + '0');
    if (rez.SZ >= ind+2) rez[ind+1] = char(rez[ind+1]-'0' + zn/10 + '0');
    else                 rez+= char(zn/10 + '0');
    ind++;
    if (ind < s1.SZ) ymn (s1[ind]-'0', ind, 2);
}

void mlp ()
{
    //cout << "s1= " << s1 << endl;
    s1 = reverse(num1);
    //for (int i = 0 ; i < s1.SZ; i++)
    //{
        ymn(s1[0]-'0', 0, 2);
    //}
    //cout << "REZ = " << rez << endl;
    num1 = reverse(rez);
    char smb = num1[0];
    while (smb == '0')
    {
        num1.erase(0,1);
        smb = num1[0];
    }
    rez = "";
}

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
}

void solution()
{
    num1 = "2";
    s2 = "2";
    for (int i = 0; i < n-1; i++)
    {
      mlp();
      //cout << num1 << endl;
    }
}

void out()
{
    //ofstream cout("output.txt");
    if (n == 0) cout << "1\n";
    if (n == 1) cout << "2\n";
    if (n > 1) cout << num1 << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
