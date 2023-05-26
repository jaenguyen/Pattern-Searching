#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;
char x[100001], y[100001];
int ASIZE = 256, m, n;
void nhap()
{
    printf("Nhap x: ");
    gets(x);
    m = strlen(x);
    printf("Nhap y: ");
    gets(y);
    n = strlen(y);
}
void SKIP(char *x, int m, char *y, int n)
{
    int i, j;
    list<int> z[ASIZE];
    list<int>::iterator it;
    /*preprocessing */
    for (i = m - 1; i >= 0; i--)
    {
        z[x[i]].push_back(i);
    }
    /* search */
    for (j = m - 1; j < n; j += m)
    {
        for (it = z[y[j]].begin();
             it != z[y[j]].end();
             it++)
        {
            if (memcmp(x, y + j - (*it), m) == 0)
                printf("position is %d\n", j - (*it));
        }
    }
}
main()
{
    nhap();
    SKIP(x, m, y, n);
}