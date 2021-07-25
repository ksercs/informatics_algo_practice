#include <iostream>

using namespace std;

int n, ans;

void in()
{
    cin >> n;
}

void solution()
{
    int ch = 1;
    while(ch < n)
    {
        ch*=2;
        ans++;
    }
}

void out()
{
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
