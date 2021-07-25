#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, q, ln, lvl, fl;

pair <int ,int> tree[262143+2];

vector <pair <int, int> > ans;

pair <int ,int> pred(int x)
{
  return tree[(x/2)];
}

pair <int ,int> potom(int x, int lr)
{
  return tree[(2*x + lr)];
}

int lvl_count(int x)
{
    int level=1, ch=1;
    while(ch<x)
    {
     ch*=2;
     level++;
    }
    return level;
}

void iniz_t()
{
  for (int i = (ln+1)/2-1; i >=1; i--)
  {
      pair <int,int> l_p, r_p;
      l_p=potom(i,0);
      r_p=potom(i,1);
      if (l_p > r_p) tree[i]=l_p;
      else tree[i]=r_p;
  }
}

void make_btree(int b)
{
  lvl = lvl_count(b);
  ln = (1<<(lvl))-1;
}

pair <int, int> Search(int v, int vL, int vR, int sL, int sR)
{
    //cout << v << " " <<vL << " " <<vR << " " <<sL << " " <<sR << "\n";
    if( (vL != sL) || (vR != sR) )
    {
        int pot = (v << 1);
        int M = ((vL + vR) >> 1);
        if(sR <= M)return Search(pot, vL, M, sL, sR);
        else if(M < sL)return Search(pot + 1, M + 1, vR, sL, sR);
        else return max(Search(pot, vL, M, sL, M), Search(pot + 1, M + 1, vR, M + 1, sR));
    }
    return tree[v];
}

void in()
{
    cin >> n;
    make_btree(n);
    //cout <<lvl << " " <<(ln+1)/2 << "\n";
    for (int i = (ln+1)/2; i < (ln+1)/2+n; i++)
    {
        int a;
        cin >> a;
        tree[i] = make_pair(a,i-(ln+1)/2+1);
    }
    iniz_t();
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int L, R;
        cin >> L >> R;
        ans.push_back(Search(1, 0, (ln+1)/2-1, L-1,R-1));
    }
}

void solution()
{

}

void out()
{
    /*for (int i = 1; i <= ln; i++)
    {
        cout << tree[i] << " ";
    }*/
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " "<<ans[i].second << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
