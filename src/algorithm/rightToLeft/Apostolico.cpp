#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cstring>
#define For(i, a, b) for (long i = a; i <= b; i++)
using namespace std;
char x[100001], y[100001];
int m, n, XSIZE;
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
void preKmp(char *x, int m, int kmpNext[])
{
    int i, j;
    i = 0;
    j = kmpNext[0] = -1;
    while (i < m)
    {
        while (j > -1 && x[i] != x[j])
            j = kmpNext[j];
        i++;
        j++;
        if (x[i] == x[j])
            kmpNext[i] = kmpNext[j];
        else
            kmpNext[i] = j;
    }
}
void AXAMAC(char *x, int m, char *y, int n)
{
    int i, j, k, ell, kmpNext[XSIZE];
    /* Preprocessing */
    preKmp(x, m, kmpNext);
    for (ell = 1; x[ell - 1] == x[ell]; ell++)
        ;
    if (ell == m)
        ell = 0;
    /* Searching */
    i = ell;
    j = k = 0;
    while (j <= n - m)
    {
        while (i < m && x[i] == y[i + j])
            ++i;
        if (i >= m)
        {
            while (k < ell && x[k] == y[j + k])
                ++k;
            if (k >= ell)
                printf("position is %d\n", j);
        }
        j += (i - kmpNext[i]);
        if (i == ell)
            k = max(0, k - 1);
        else if (kmpNext[i] <= ell)
        {
            k = max(0, kmpNext[i]);
            i = ell;
        }
        else
        {
            k = ell;
            i = kmpNext[i];
        }
    }
}
main()
{
    nhap();
    AXAMAC(x, m, y, n);
}