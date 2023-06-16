public class Permutations {

    public static void main(String[] args) {
      permutations("", "abc");
    }
  
    static void permutations(String p, String up) {
      // Base case: If the remaining characters to be permuted is empty, print the permutation
      if (up.isEmpty()) {
        System.out.println(p);
        return;
      }
      
      char ch = up.charAt(0);
  
      for (int i = 0; i <= p.length(); i++) {
        // Split the permutation string into two parts
        String f = p.substring(0, i); // First part
        String s = p.substring(i, p.length()); // Second part
        
        // Recursive call: Generate permutations by inserting the current character at each possible position
        permutations(f + ch + s, up.substring(1));
      }
    }
  }
  