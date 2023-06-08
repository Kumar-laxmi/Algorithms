import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class RabinKarp {
    private static final int PRIME = 101;

    public List<Integer> search(String text, String pattern) {
        List<Integer> result = new ArrayList<>();

        int n = text.length();
        int m = pattern.length();
        if (n < m)
            return result;

        long patternHash = createHash(pattern, m);
        long textHash = createHash(text, m);

        for (int i = 0; i <= n - m; i++) {
            if (patternHash == textHash && checkEqual(text, i, i + m - 1, pattern, 0, m - 1)) {
                result.add(i);
            }
            if (i < n - m) {
                textHash = recalculateHash(text, i, i + m, textHash, m);
            }
        }

        return result;
    }

    private long createHash(String str, int length) {
        long hash = 0;
        for (int i = 0; i < length; i++) {
            hash += str.charAt(i) * Math.pow(PRIME, i);
        }
        return hash;
    }

    private boolean checkEqual(String str1, int start1, int end1, String str2, int start2, int end2) {
        if (end1 - start1 != end2 - start2) {
            return false;
        }
        while (start1 <= end1 && start2 <= end2) {
            if (str1.charAt(start1) != str2.charAt(start2)) {
                return false;
            }
            start1++;
            start2++;
        }
        return true;
    }

    private long recalculateHash(String str, int oldIndex, int newIndex, long oldHash, int patternLength) {
        long newHash = oldHash - str.charAt(oldIndex);
        newHash /= PRIME;
        newHash += str.charAt(newIndex) * Math.pow(PRIME, patternLength - 1);
        return newHash;
    }

    public static void main(String[] args) {
        RabinKarp rk = new RabinKarp();

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the text: ");
        String text = scanner.nextLine();

        System.out.print("Enter the pattern: ");
        String pattern = scanner.nextLine();

        List<Integer> occurrences = rk.search(text, pattern);
        System.out.println("Pattern found at indices: " + occurrences);
    }
}
