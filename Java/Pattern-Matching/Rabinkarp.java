import java.util.Scanner;

public class Rabinkarp {

    private final int prime;
    private final int patternHash;
    private final int[] powers;
    private final String pattern; // add this field



    public Rabinkarp(String pattern, int prime) {
        this.prime = prime;
        this.pattern = pattern; // initialize this field
        this.patternHash = hash(pattern, prime, 0, pattern.length() - 1);
        this.powers = new int[pattern.length()];
        powers[0] = 1;
        for (int i = 1; i < pattern.length(); i++) {
            powers[i] = powers[i - 1] * prime % Integer.MAX_VALUE;
        }
    }


    public int search(String text) {
        int n = text.length();
        int m = powers.length;
        int textHash = hash(text, prime, 0, m - 1);
        if (textHash == patternHash && check(text, 0)) {
            return 0;
        }

        for (int i = 1; i <= n - m; i++) {
            textHash = (textHash + prime - powers[m - 1] * text.charAt(i - 1) % Integer.MAX_VALUE) % Integer.MAX_VALUE;
            textHash = (textHash * prime + text.charAt(i + m - 1)) % Integer.MAX_VALUE;
            if (textHash == patternHash && check(text, i)) {
                return i;
            }
        }

        return -1;
    }

    private int hash(String str, int prime, int start, int end) {
        int hash = 0;
        for (int i = start; i <= end; i++) {
            hash = (hash * prime + str.charAt(i)) % Integer.MAX_VALUE;
        }
        return hash;
    }

    private boolean check(String text, int start) {
        for (int i = 0; i < powers.length; i++) {
            if (text.charAt(start + i) != pattern.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the pattern to search for: ");
        String pattern = scanner.nextLine();
        System.out.print("Enter the text to search in: ");
        String text = scanner.nextLine();

        Rabinkarp rabinkarp = new Rabinkarp(pattern, 31);
        int index = rabinkarp.search(text);

        if (index == -1) {
            System.out.println("Pattern not found in the text");
        } else {
            System.out.println("Pattern found at index " + index);
        }
    }
}

