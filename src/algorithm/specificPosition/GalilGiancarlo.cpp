void GG(char *x, int m, char *y, int n)
{
    int i, j, k, ell, last, nd;
    int h[XSIZE], next[XSIZE], shift[XSIZE];
    char heavy;
    for (ell = 0; x[ell] == x[ell + 1]; ell++)
        ;
    if (ell == m - 1)
        /* Searching for a power of a single character */
        for (j = ell = 0; j < n; ++j)
            if (x[0] == y[j])
            {
                ++ell;
                if (ell >= m)
                    OUTPUT(j - m + 1);
            }
            else
                ell = 0;
    else
    {
        /* Preprocessing */
        nd = preCOLUSSI(x, m, h, next, shift);
        /* Searching */
        i = j = heavy = 0;
        last = -1;
        while (j <= n - m)
        {
            if (heavy && i == 0)
            {
                k = last - j + 1;
                while (x[0] == y[j + k])
                    k++;
                if (k <= ell || x[ell + 1] != y[j + k])
                {
                    i = 0;
                    j += (k + 1);
                    last = j - 1;
                }
                else
                {
                    i = 1;
                    last = j + k;
                    j = last - (ell + 1);
                }
                heavy = 0;
            }
            else
            {
                while (i < m && last < j + h[i] &&
                       x[h[i]] == y[j + h[i]])
                    ++i;
                if (i >= m || last >= j + h[i])
                {
                    OUTPUT(j);
                    i = m;
                }
                if (i > nd)
                    last = j + m - 1;
                j += shift[i];
                i = next[i];
            }
            heavy = (j > last ? 0 : 1);
        }
    }
}