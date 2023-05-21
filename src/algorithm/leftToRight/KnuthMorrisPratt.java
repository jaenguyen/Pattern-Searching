package algorithm.leftToRight;

public class KnuthMorrisPratt {

    // hàm tiền xử lý
    public static int[] preKMP(char[] x) {
        int[] kmpNext = new int[x.length + 1];
        int i = 1, len = 0;
        kmpNext[0] = 0; //kmpNext[0] luôn là 0
        while (i < x.length) {
            if (x[i] == x[len]) { //Nếu X[i] = X[len]
                len++;
                kmpNext[i] = len;
                i++;
            } else { // Nếu X[i] != X[len]
                if (len != 0) {
                    len = kmpNext[len - 1];
                } else {
                    kmpNext[i] = 0;
                    i++;
                }
            }
        }
        return kmpNext;
    }

    public static void search(char[] x, char[] y) {
        int[] kmpNext = preKMP(x);
        int i = 0, j = 0;
        while (i < y.length) {
            if (x[j] == y[i]) {
                i++;
                j++;
            }
            if (j == x.length) {
                System.out.print(i - j + " ");
                j = kmpNext[j - 1];
            } else if (i < y.length && x[j] != y[i]) {
                if (j != 0) j = kmpNext[j - 1];
                else i = i + 1;
            }
        }
    }

    public static void main(String[] args) {
        search("AAEBAAE".toCharArray(), "EBAAEBAAEBAAEA".toCharArray());
    }
}
