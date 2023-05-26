package algorithm.randomPosition;

import algorithm.Compare;

public class Smith {

    public static int[] preQsBc(char[] x) {
        int[] bc = new int[255];
        int m = x.length;
        for (int i = 0; i < 255; i++) {
            bc[i] = m + 1;
        }
        for (int i = 0; i < m; i++) {
            bc[(int) x[i]] = m - i;
        }
        return bc;
    }

    public static int[] preBc(char[] x) {
        int[] bc = new int[255];
        int m = x.length;
        for (int i = 0; i < 255; i++) {
            bc[i] = m;
        }
        for (int i = 0; i < m - 1; i++) {
            bc[(int) x[i]] = m - i - 1;
        }
        return bc;
    }

    public static void search(char[] x, char[] y) {
        int m = x.length;
        int n = y.length;
        int[] preBc = preBc(x);
        int[] preQsBc = preQsBc(x);
        int i = 0;
        while (i <= n - m) {
            if (Compare.cmp(x, y, i)) {
                System.out.print(i + " ");
            }
            i += Math.max(preBc[y[i + m - 1]], preQsBc[y[i + m]]);
        }
    }

    public static void main(String[] args) {
        search("JAE".toCharArray(), "ABJAECD".toCharArray());
    }
}
