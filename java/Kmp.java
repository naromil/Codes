import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Kmp {

    static int[] next = new int[1000005];
    private static void getNext(String b) {
        int i = 0, j = -1;
        next[0] = -1;
        while (i + 1 < b.length()) {
            if (b.charAt(i + 1) == b.charAt(j + 1)) {
                i++;
                j++;
                next[i] = j;
            } else if (j != -1) {
                j = next[j];
            } else {
                i++;
                next[i] = -1;
            }
        }
    }

    private static List<Integer> kmp(String a, String b) {
        int i = -1, j = -1;
        List<Integer> ansList = new ArrayList<>();

        while (i + 1 < a.length()) {
            if (a.charAt(i + 1) == b.charAt(j + 1)) {
                i++;
                j++;
                if (j == b.length() - 1) {
                    ansList.add(i - j + 1);
                    j = next[j];
                }
            } else if (j != -1) {
                j = next[j];
            } else {
                i++;
            }
        }

        return ansList;
    }

    public static void main(String[] args) {

        Scanner scr = new Scanner(System.in);
        String a = scr.next();
        String b = scr.next();

        getNext(b);

        List<Integer> ansList = kmp(a, b);
        for (int ans : ansList) {
            System.out.println(ans);
        }

        for (int i = 0; i < b.length(); i++) {
            System.out.print((next[i] + 1) + " ");
        }
        System.out.println();

        scr.close();
    }
}
