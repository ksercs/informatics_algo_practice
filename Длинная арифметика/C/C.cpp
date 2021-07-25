#include <iostream>
#include <fstream>
#include <string>

#define SZ size()

using namespace std;

string num1, num2, sum, s2;
int fl;

string reverse( string s)
{
    int n = (int)s.SZ;
    for (int i=0; i < n/2; i++)
       swap(s[i], s[n-i-1]);
    return s;
}

void pl(int ind, int z2)
{
  //  cout << ind << " " << " " << z2 << endl;
    int zn = (sum[ind]-'0') + z2;
    if ( zn <= 9 )  sum[ind] = (char)(zn + '0');
    else
    {
        sum[ind] = (char)(zn%10+'0');
        if (ind == sum.SZ-1) {sum += (char)(zn/10 +'0'); fl = 1;}
        else                 sum[ind+1] = (char)( ((sum[ind+1]-'0') + zn/10) +'0');
    }
  //  cout << sum[ind] << endl;
    ind++;
    if (ind != sum.SZ && !fl) pl(ind, s2[ind]-'0');
}

void get_sum(string s1, string ss2)
{
    if (s1.SZ < s2.SZ) swap(s1, s2);
    sum = reverse(s1);
    s2 = reverse(ss2);
    for (int i = s2.SZ; i < sum.SZ; i++)
    {
        s2 += '0';
    }
    //cout << s1 <<  " " << s2 << endl;
    pl(0, s2[0]-'0');
}

void in()
{
    ifstream cin("input.txt");
    cin >> num1 >> num2;
}

void solution()
{
    get_sum(num1, num2);
    //cout << sum << endl;
    sum = reverse(sum);
}

void out()
{
    ofstream cout("output.txt");
    cout << sum << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
