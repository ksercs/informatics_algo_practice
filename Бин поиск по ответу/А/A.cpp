#include <iostream>
#include <algorithm>

using namespace std;

long long h, w, n;

long long bin_search(int cnt)
{
    long long L = 0, R = h*cnt;
    while(R - L > 1)
    {
        long long m = L + (R-L)/2;
        if ( (m/w) *(m/h) < cnt) L = m;
        else                     R = m;
    }
    return R;
}

void in()
{
    cin >> h >> w >> n;
}

void solution()
{
    if (w < h) swap(w,h);
}

void out()
{
    cout << bin_search(n) << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
