package algorithm;

public class Compare {
    public static boolean cmp(char[] x, char[] y, int y1) {
        for (int i = 0; i < x.length; i++) {
            if (x[i] != y[y1++]) {
                return false;
            }
        }
        return true;
    }
}
