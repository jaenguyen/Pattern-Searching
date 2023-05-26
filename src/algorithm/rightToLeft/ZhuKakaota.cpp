#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cstring>
#define For(i, a, b) for (long i = a; i <= b; i++)
using namespace std;
char x[100001], y[100001];
int m, n, ASIZE = 256, XSIZE;
void nhap()
{
    printf("Nhap x: ");
    gets(x);
    m = strlen(x);
    XSIZE = m;
    printf("Nhap y: ");
    gets(y);
    n = strlen(y);
}
void suffixes(char *x, int m, int *suff)
{
    int f, g, i;
    suff[m - 1] = m;
    g = m - 1;
    for (i = m - 2; i >= 0; --i)
    {
        if (i > g && suff[i + m - 1 - f] < i - g)
            suff[i] = suff[i + m - 1 - f];
        else
        {
            if (i < g)
                g = i;
            f = i;
            while (g >= 0 && x[g] == x[g + m - 1 - f])
                --g;
            suff[i] = f - g;
        }
    }
}
void preBmGs(char *x, int m, int bmGs[])
{
    int i, j, suff[XSIZE];
    suffixes(x, m, suff);
    for (i = 0; i < m; ++i)
        bmGs[i] = m;
    j = 0;
    for (i = m - 1; i >= 0; --i)
        if (suff[i] == i + 1)
            for (; j < m - 1 - i; ++j)
                if (bmGs[j] == m)
                    bmGs[j] = m - 1 - i;
    for (i = 0; i <= m - 2; ++i)
        bmGs[m - 1 - suff[i]] = m - 1 - i;
}
void preZtBc(char *x, int m, int ztBc[256][256])
{
    int i, j;
    for (i = 0; i < ASIZE; ++i)
        for (j = 0; j < ASIZE; ++j)
            ztBc[i][j] = m;
    for (i = 0; i < ASIZE; ++i)
        ztBc[i][x[0]] = m - 1;
    for (i = 1; i < m - 1; ++i)
        ztBc[x[i - 1]][x[i]] = m - 1 - i;
}
void ZT(char *x, int m, char *y, int n)
{
    int i, j, ztBc[256][256], bmGs[XSIZE];
    /* Preprocessing */
    preZtBc(x, m, ztBc);
    preBmGs(x, m, bmGs);
    /* Searching */
    j = 0;
    while (j <= n - m)
    {
        i = m - 1;
        while (i < m && x[i] == y[i + j])
            --i;
        if (i < 0)
        {
            printf("position is %d\n", j);
            j += bmGs[0];
        }
        else
            j += max(bmGs[i], ztBc[y[j + m - 2]][y[j + m - 1]]);
    }
}
main()
{
    nhap();
    ZT(x, m, y, n);
}