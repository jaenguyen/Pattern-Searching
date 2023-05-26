#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <set>
#include <cstring>
#define For(i, a, b) for (long i = a; i <= b; i++) typedef int Graph[10001][256];
using namespace std;
Graph aut;
char x[10001], y[100001];
int m, n, ASIZE;
string s = "";
void nhap()
{
    printf("Nhap x: ");
    gets(x);
    m = strlen(x);
    printf("Nhap y: ");
    gets(y);
    n = strlen(y);
    ASIZE = 0;
    set<char> se;
    for (int i = 0; i < m; i++)
        if (se.find(x[i]) == se.end())
        {
            se.insert(x[i]);
            s += x[i];
            ASIZE++;
        }
    for (int i = 0; i < n; i++)
        if (se.find(y[i]) == se.end())
        {
            se.insert(y[i]);
            s += y[i];
            ASIZE++;
        }
}
void preAut(char *x, int m, Graph aut)
{
    memset(aut, 0, sizeof(aut));
    aut[0][x[0]] = 1;
    aut[1][x[0]] = 1;
    For(i, 2, m)
    {
        int vt = aut[i - 1][x[i - 1]];
        for (int j = 0; j < ASIZE; j++)
        {
            aut[i][s[j]] = aut[vt][s[j]];
        }
        aut[i - 1][x[i - 1]] = i;
    }
}
void AUT()
{
    int state = 0;
    for (int i = 0; i < n; i++)
    {
        state = aut[state][y[i]];
        if (state == m)
            printf("position is %d \n", i - m + 1);
    }
}
main()
{
    nhap();
    preAut(x, m, aut);
    AUT();
}