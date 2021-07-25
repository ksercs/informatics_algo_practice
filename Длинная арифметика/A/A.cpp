#include <iostream>
#include <fstream>
#include <string>

#define SZ size()

using namespace std;

int s, zn;
string num;

void mn(int ind, int ch)
{
    if (ind == -1) {num = char(ch+'0')+num; return;}
    int z = num[ind]-'0';
    if (z >= ch)
        num[ind] = char((z-ch)+'0');
    else
    {
        num[ind] = char((9-(ch-z)+1)+'0');
        mn(ind-1, 1);
    }
}

void pl(int ind, int ch)
{
    if (ind == -1) {num = char(ch+'0')+num; return;}
    int z = num[ind]-'0';
    if (z >= 0 && z <= 9-ch)
        num[ind] = (z+ch)+'0';
    else
    {
        num[ind] = '0';
        pl(ind-1, ch-(9-z));
    }
}

void in()
{
    //ifstream cin("input.txt");
    cin >> num;
}

void solution()
{
    if (num[0] == '-') {num.erase(0,1); zn = -1;}
    else                zn = 1;
    s = num.SZ;
    if (zn == 1) pl(s-1, 1);
    else    mn(s-1, 1);
}

void out()
{
    //ofstream cout("output.txt");
    int fl = 0;
    if (num[0] == '0') num.erase(0, 1);
    if (num.SZ == 0) fl = 1;
    if (fl) cout << "0\n";
    else
    {if (zn == 1) cout << num << endl;
    else    cout << "-" << num << endl;}
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
