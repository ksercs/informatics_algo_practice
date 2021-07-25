#include <iostream>
#include <fstream>
#include <string>

#define SZ size()

using namespace std;

string num1, num2, rez, s1, s2, s3, sum="0";
int st, dop, fl;

void pl(int ind, int z2)
{
  //  cout << ind << " " << " " << z2 << endl;
    int zn = (sum[ind]-'0') + z2;
    if ( zn <= 9 )  sum[ind] = (char)(zn + '0');
    else
    {
        sum[ind] = (char)(zn%10+'0');
        if (ind == sum.SZ-1) {sum+= (char)(zn/10 +'0'); fl = 1;}
        else                 sum[ind+1] = (char)( ((sum[ind+1]-'0') + zn/10) +'0');
    }
  //  cout << sum[ind] << endl;
    ind++;
    if (ind != sum.SZ && !fl) pl(ind, s3[ind]-'0');
}


string reverse( string s)
{
    int n = (int)s.SZ;
    for (int i=0; i < n/2; i++)
       swap(s[i], s[n-i-1]);
    return s;
}

void get_sum(string ss2)
{
    s3 = ss2;
    for (int i = s3.SZ; i < sum.SZ; i++)
    {
        s3 += '0';
    }
    //cout << s1 <<  " " << s2 << endl;
    pl(0, s3[0]-'0');
}

void ymn (int mn, int ind, int z)
{
   // cout << mn << " " << ind << " " << z << endl;
    int zn = mn*z;
    //cout << "ZN = " << zn << endl;
    if (rez.SZ >= ind+1) rez[ind] = char(rez[ind]-'0' + zn%10 + '0');
    else                 rez += char(zn%10 + '0');
    if (rez.SZ >= ind+2) rez[ind+1] = char(rez[ind+1]-'0' + zn/10 + '0');
    else                 rez += char(zn/10 + '0');
    ind++;
    if (ind < s2.SZ) ymn (mn, ind, s2[ind]-'0');
}

void mlp (string ss1, string ss2)
{
    s1 = reverse(ss1);
    s2 = reverse(ss2);
    //cout << "s1= " << s1 << endl;
    //cout << "s2= " << s2 << endl;
    for (int i = 0 ; i < s1.SZ; i++)
    {
        ymn(s1[i]-'0', 0, s2[0]-'0');
        for (int j = 0; j < st; j++)
        {
            rez = '0'+rez;
        }
        for (int j = sum.SZ; j < rez.SZ; j++)
        {
            sum +='0';
        }
       // cout << rez << endl;
        get_sum(rez);
        //cout << sum << endl;
        st++;
        rez="";
    }
}

void in()
{
    //ifstream cin("input.txt");
    cin >> num1 >> num2;
}

void solution()
{
    if (num1.SZ < num2.SZ) swap(num1, num2);
    mlp(num1, num2);
    sum = reverse(sum);
    int smb = sum[0];
    while (smb == '0')
    {
        sum.erase(0,1);
        smb = sum[0];
    }
}

void out()
{
    //ofstream cout("output.txt");
    if (sum.SZ == 0) cout << "0\n";
    else             cout << sum << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
