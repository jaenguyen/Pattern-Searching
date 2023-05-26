package algorithm.leftToRight;

import java.util.Arrays;

public class RabinKarp {
    public static int hash(char[] x) {
        int result = 0;
        for (int i = 0; i < x.length; i++) {
            result = (int) (result + (int) x[i] * Math.pow(2, x.length - i - 1));
        }
        return result;
    }

    // tính giá trị băm của 1 mảng kí tự dựa t rên giá trị băm đã tính trước đó
    // a: là kí tự đầu tiên của mảng trước đó
    // b: là kí tự cuối cùng của mảng mới
    // h: là giá trị băm của mảng cũ
    // m: là chiều dài của chuỗi cần so sánh
    public static int rehash(char a, char b, int h, int m) {
        int result = 0;
        result = (int) ((2 * (h - a * Math.pow(2, m - 1))) + b);
        return result;
    }

    // in ra các vị trí của x trong y
    public static void search(char[] x, char[] y) {
        int hx = hash(x);
        char[] init = Arrays.copyOfRange(y, 0, x.length);
        int hy = hash(init);
        System.out.println("hx= " + hx);
        System.out.println("hy ban dau= " + hy);
        if (hx == hy) {
            System.out.println("Vị trí trùng nhau: 0");
        }
        for (int i = 1; i <= y.length - x.length; i++) {
            hy = rehash(y[i - 1], y[i + x.length - 1], hy, x.length);
            // System.out.println(hy);
            if (hx == hy) {
                System.out.println("vị trí trùng nhau: " + i);
            }
        }
    }

    public static void main(String[] args) {
        search("AAEBAAE".toCharArray(), "EBAAEBAAEBAAEA".toCharArray());
    }
}
