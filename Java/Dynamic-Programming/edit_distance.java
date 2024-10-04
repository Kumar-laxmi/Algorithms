public class GfG {
    // A Naive recursive Java program to find minimum number
    // of operations to convert s1 to s2
    public static int editDistRec(String s1, String s2, int m, int n) {
        // If first string is empty, the only option is to
        // insert all characters of second string into first
        if (m == 0) return n;

        // If second string is empty, the only option is to
        // remove all characters of first string
        if (n == 0) return m;

        // If last characters of two strings are same, nothing
        // much to do. Get the count for
        // remaining strings.
        if (s1.charAt(m - 1) == s2.charAt(n - 1))
            return editDistRec(s1, s2, m - 1, n - 1);

        // If last characters are not same, consider all three
        // operations on last character of first string,
        // recursively compute minimum cost for all three
        // operations and take minimum of three values.
        return 1 + Math.min(Math.min(editDistRec(s1, s2, m, n - 1),    // Insert
                                      editDistRec(s1, s2, m - 1, n)),  // Remove
                             editDistRec(s1, s2, m - 1, n - 1));     // Replace
    }

    // Wrapper function to initiate the recursive calculation
    public static int editDist(String s1, String s2) {
        return editDistRec(s1, s2, s1.length(), s2.length());
    }

    // Driver code
    public static void main(String[] args) {
        String s1 = "GEEXSFRGEEKKS";
        String s2 = "GEEKSFORGEEKS";
        System.out.println(editDist(s1, s2));
    }
}