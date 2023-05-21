package algorithm.leftToRight;

public class BruteForce {

    static void search(char[] x, char[] y) {
        int m = x.length;
        int n = y.length;
        for (int j = 0; j <= n - m; j++) {
            for (int i = 0; i < m && x[i] == y[i + j]; i++) {
                if (i >= m - 1) {
                    System.out.print(j + " ");
                }
            }
        }
    }

    public static void main(String[] args) {
        search("GCAGAGAG".toCharArray(), "GCATCGCAGAGAGTATACAGTACGGCAGAGAG".toCharArray());
    }
}
