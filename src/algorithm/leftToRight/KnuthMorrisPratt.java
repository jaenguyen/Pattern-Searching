package algorithm.leftToRight;

public class KnuthMorrisPratt {

    static int[] preKMP(char[] x) {
        int[] kmpNext = new int[x.length + 1];
        int i = 0, j = -1;
        kmpNext[0] = -1;
        while (i < x.length - 1) {
            while (j > -1 && x[i] != x[j]) {
                j = kmpNext[j];
            }
            i++;
            j++;
            if (x[i] == x[j]) {
                kmpNext[i] = kmpNext[j];
            } else {
                kmpNext[i] = j;
            }
        }
        return kmpNext;
    }

    static void search(char[] x, char[] y) {
        int[] kmpNext = preKMP(x);
        int i = 0, j = 0;
        while (j < y.length) {
            while (i > -1 && x[i] != y[j]) {
                i = kmpNext[i];
            }
            i++;
            j++;
            if (i >= x.length) {
                System.out.print(j - i + " ");
                i = kmpNext[i];
            }
        }
    }

    public static void main(String[] args) {
        search("GCAGAGAG".toCharArray(), "GCATCGCAGAGAGTATACAGTACGGCAGAGAG".toCharArray());
    }
}
