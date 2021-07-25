#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_SIZE = 115;

int v_c, answer = 1;
int used[MAX_SIZE];

vector <vector <int> > gr;

string ans[]={"NO\n","YES\n"};

void DFS(int v)
{
    used[v] = 1;
    for (int i = 0; i < gr[v].size(); i++)
    {
        int to = gr[v][i];
        if (used[to]==2) answer = 0;
        if (used[to]==0)
        {
            used[to] = 1;
            DFS(to);
            used[to] = 2;
        }
    }
    used[v] = 2;
}

void in()
{
    //ifstream cin("C.in");
    cin >>v_c;
    gr.resize(v_c+1);
    for (int i = 1; i < v_c; i++)
    {
        for (int g = 1; g < v_c; g++)
        {
            int ch;
            cin >> ch;
            if (ch) {gr[i].push_back(g);}
        }
    }
}

void solution()
{
    DFS(1);
}

void out()
{
    //ofstream cout("C.out");
    cout << ans[answer];
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
