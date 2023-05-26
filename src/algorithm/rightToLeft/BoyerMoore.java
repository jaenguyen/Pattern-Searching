package algorithm.rightToLeft;

public class BoyerMoore {

    public static final int ASize = 26;

    static void preBM(char[] x, int preBM[]) {
        int m = x.length;
        for (int i = 0; i < ASize; i++) {
            preBM[i] = m;
        }
        for (int i = 0; i < m - 1; i++) {
            preBM[x[i] - 65] = m - i - 1;
        }
    }

    static void search(char[] x, char[] y, int[] preBM) {
        int m = x.length, n = y.length;
        int j = m - 1;
        while (j < y.length) {
            boolean check = false;
            for (int i = m - 1; i >= 0; i--) {
                if (x[i] != y[j - (m - i - 1)]) {
                    check = true;
                    break;
                }
            }
            if (!check) {
                System.out.print(j + " ");
            }
            j += preBM[y[j] - 65];
        }
    }

    public static void main(String[] args) {
        int[] preBM = new int[ASize];
        char x[] = "AAEBAAE".toCharArray();
        char y[] = "EBAAEBAAEBAAEA".toCharArray();
        preBM(x, preBM);
        search(x, y, preBM);
    }
}
