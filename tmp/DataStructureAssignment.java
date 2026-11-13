import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.TreeMap;

public class DataStructureAssignment {

    // question 4B
    public static <T> T q4b(Stack<T> stk) {
        Stack<T> stk2 = new Stack<>();
        T lastElement = null;

        while (!stk.isEmpty()) {
            lastElement = stk.pop();
            stk2.push(lastElement);
        }

        if (!stk2.isEmpty()) stk2.pop();

        while (!stk2.isEmpty()) {
            stk.push(stk2.pop());
        }
        return lastElement;
    }

    // question 5
    public static void q5() {
        Set<Integer> st = new LinkedHashSet<>();
        for (int i = 2; i <= 12; i++) {
            st.add(i);
        }

        while (!st.isEmpty()) {
            int lst = 0;

            System.out.print("Remaining: ");
            for (int x : st) {
                lst = x;
                System.out.print(x + " ");
            }
            System.out.println();

            if (st.size() == 1) {
                System.out.println("Winner: " + lst);
                break;

            } else {
                int x = (int) (Math.random() * 6 + 1);
                int y = (int) (Math.random() * 6 + 1);
                int sum = x + y;
                System.out.println("Roll: " + x + "+" + y + "=" + sum);

                if (st.contains(sum)) st.remove(sum);
            }
        }
    }

    // question 6
    public static <T> List<T> q6(List<T> arr) {
        List<T> a2 = new ArrayList<>();
        Set<T> st = new HashSet<>();

        for (T x : arr) {
            if (st.contains(x)) continue;
            st.add(x);
            a2.add(x);
        }

        System.out.println("Original data:\n" + arr + "\nFinal data:\n" + a2);

        return a2;
    }

    // question 7
    public static Queue<Integer> q7(Queue<Integer> q) {
        Queue<Integer> ground = new LinkedList<>();
        Queue<Integer> balcony = new LinkedList<>();

        System.out.println("Original lineup:\n" + q);

        while (!q.isEmpty()) {
            int x = q.remove();
            if (x <= 200) ground.add(x); // suppose 200 itself is in ground group
            else balcony.add(x);
        }
        while (!balcony.isEmpty()) {
            int x = balcony.remove();
            ground.add(x);
        }

        System.out.println("\nReorganized lineup:\n" + ground);

        return ground;
    }

    // question 8
    private record SpellType(int damage, int cost) {}
    private static Map<String, SpellType> spells = new HashMap<>();
    public static void initializeSpell() {
        spells.put("Fireball", new SpellType(5, 4));
        spells.put("Lightning", new SpellType(6, 4));
        spells.put("Earthquake", new SpellType(2, 6));
        spells.put("Fly", new SpellType(0, 5));
        spells.put("EnergyBeam", new SpellType(7, 5));
    }

    public static SpellType q8(String call) {
        return spells.get(call);
    }

    // question 9
    private static Map<Character, Character> encrypt = new HashMap<>();
    private static Map<Character, Character> decrypt = new HashMap<>();
    private static void initializeEncryption() {
        String key = "jbzefrnhsguixykaocpdqltvmw";
        for (int i = 0; i < 26; i++) {
            encrypt.put((char) ('a' + i), key.charAt(i));
        }

        for (Map.Entry<Character, Character> entry : encrypt.entrySet()) {
            decrypt.put(entry.getValue(), entry.getKey());
        }
    }

    public static void q9() {
        Scanner scr = new Scanner(System.in);
        while (true) {
            System.out.print("How can I serve you my master? ");
            String s = scr.next();
            if (s.isBlank()) break;
            char op = s.charAt(0);
            if (op != 'E' && op != 'D') break;
            s = s.substring(1);

            char[] ns = new char[s.length()];
            for (int i = 0; i < s.length(); i++) {
                char x = s.charAt(i);
                if (x >= 'a' && x <= 'z') ns[i] = (op == 'E' ? encrypt : decrypt).get(x);
            }

            String ss = new String(ns);

            if (op == 'E') {
                System.out.println("\nWord: " + s + "\nEncrypted: " + ss);
            } else {
                System.out.println("\nEncrypted: " + s + "\nWord: " + ss);
            }
        }
        scr.close();
    }

    // question 10
    private static TreeMap<String, Integer> map = new TreeMap<String, Integer>();
    private static void initializeScrabble() {
        map.put("A", 1); map.put("B", 3); map.put("C", 3); map.put("D", 2);
        map.put("E", 1); map.put("F", 4); map.put("G", 2); map.put("H", 4);
        map.put("I", 1); map.put("J", 8); map.put("K", 5); map.put("L", 1);
        map.put("M", 3); map.put("N", 1); map.put("O", 1); map.put("P", 3);
        map.put("Q", 10); map.put("R", 1); map.put("S", 1); map.put("T", 1);
        map.put("U", 1); map.put("V", 4); map.put("W", 4); map.put("X", 8);
        map.put("Y", 4); map.put("Z", 10);
    }

    public static int q10(String word) {
        int res = 0;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (ch >= 'a' && ch <= 'z') ch -= 32;
            if (ch >= 'A' && ch <= 'Z') res += map.get(String.valueOf(ch));
        }

        return res;
    }

    // main: initialize
    public static void main(String[] args) {
        initializeSpell();
        initializeEncryption();
        initializeScrabble();
        return;
    }
}
