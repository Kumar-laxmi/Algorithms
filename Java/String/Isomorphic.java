/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms*/
import java.util.*;
public class Isomorphic 
{
    public static boolean isIsomorphic(String s, String t) 
    {
        // Create two hash maps to store the mappings between s and t, and t and s
        Map<Character, Character> s_to_t = new HashMap<>();
        Map<Character, Character> t_to_s = new HashMap<>();
        // Iterate through each character in the strings and compare their corresponding mappings
        for (int i = 0; i < s.length(); i++) {
            // If there is a mismatch in either of the hash maps, the strings are not isomorphic
            if (s_to_t.containsKey(s.charAt(i)) && s_to_t.get(s.charAt(i)) != t.charAt(i))
            {
                return false;
            }
            if (t_to_s.containsKey(t.charAt(i)) && t_to_s.get(t.charAt(i)) != s.charAt(i)) 
            {
                return false;
            }
            // Add the new mappings to both hash maps
            s_to_t.put(s.charAt(i), t.charAt(i));
            t_to_s.put(t.charAt(i), s.charAt(i));
        }
        // If we reach the end of the strings without finding a mismatch, the strings are isomorphic
        return true;
    }
    public static void main(String[] args) 
    {
        // Take input from the user
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the first string: ");
        String s = scanner.next();
        System.out.print("Enter the second string: ");
        String t = scanner.next();
        // Check if the strings are isomorphic and print the result
        if (isIsomorphic(s, t)) {
            System.out.println("The strings are isomorphic.");
        } else {
            System.out.println("The strings are not isomorphic.");
        }
    }
}