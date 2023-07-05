/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
/*Problem Description
Program to convert  text sentence in CamelCase format .
Examples:
 1] INPUT: "this is camel case"
    OUTPUT "thisIsCamelCase"
 2] INPUT: "Hi Atul here"
   OUTPUT: "HiAtulHere"
   Example Explanation */
import java.util.Scanner;
class Main {
    // Function to remove spaces and convert into camel case
    static String convert(String s) {
        boolean flag = false;
        int n = s.length();
        char ch[] = s.toCharArray();
        StringBuilder camelCase = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (i == 0) camelCase.append(Character.toLowerCase(ch[0])); // Converts to lowercase
            else if (ch[i] == ' ') flag = true; // Check for spaces in the sentence
            else if (flag && ch[i] != ' ') {
                camelCase.append(Character.toUpperCase(ch[i])); // Converts to uppercase
                flag = false;
            } 
            else camelCase.append(Character.toLowerCase(ch[i])); // Converts to lowercase
        }
        return camelCase.toString();
    }

    // Main function
    public static void main(String args[]) {
        Scanner inp = new Scanner(System.in);
        System.out.print("Enter the number of test cases: ");
        int testCase = inp.nextInt();
        inp.nextLine(); // Clear the input buffer
        for (int i = 0; i < testCase; i++) {
            System.out.print("Enter a sentence: ");
            String str = inp.nextLine();
            System.out.println("Original: " + str);
            System.out.println("Camel Case: " + convert(str) + "\n");
        }
        inp.close();
    }
}
