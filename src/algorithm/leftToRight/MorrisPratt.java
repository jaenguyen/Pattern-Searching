package algorithm.leftToRight;

public class MorrisPratt {

    // tim kiem cac vi tri cua x trong y
    // m: là vị trí tương ứng trên y bắt đầu 1 phép so sánh với x
    // mpNext[i] duoc dinh nghi la so phan tu quay nguoc lai de so sanh
    // ke tu vi tri i tren y khi ma y[m+i] khong khop voi x[i]
    public static int[] preMP(char[] x) {
        int[] mpNext = new int[x.length + 1];
        int i = 0;
        int j = mpNext[0] = -1;
        while (i < x.length) {
            while (j > -1 && (x[i] != x[j])) {
                j = mpNext[j];
            }
            mpNext[++i] = ++j;
        }
        return mpNext;
    }

    public static void search(char[] x, char[] y) {
        int[] mpNext = preMP(x);
        int i = 0;// the position of character in x
        int m = 0;// the beginning of the current match in y
        while (m <= y.length - x.length) {
            if (x[i] == y[m + i]) {
                i++;
                if (i == x.length) {
                    System.out.print(m + " ");
                    m = m + i - mpNext[i];
                    i = 0;
                }
            } else {
                m = m + i - mpNext[i];
                if (i > 0) {
                    i = mpNext[i];
                }
            }
        }
    }

    public static void main(String[] args) {
        search("AAEBAAE".toCharArray(), "EBAAEBAAEBAAEA".toCharArray());
    }
}
