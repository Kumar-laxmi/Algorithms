/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
/* Problem Statement : Given a Roman numeral, the task is to convert it into its decimal equivalent.
EXAMPLES : 
1)
Input:  "XXI"
Output: 21
2)
Input:  "MCMXCIV"
Output: 1994 */
import java.util.Scanner;
public class Roman_to_Decimal 
{
    static int value(char r) 
    {
        // Returns the decimal value of a Roman numeral
        if (r == 'I')
            return 1;
        if (r == 'V')
            return 5;
        if (r == 'X')
            return 10;
        if (r == 'L')
            return 50;
        if (r == 'C')
            return 100;
        if (r == 'D')
            return 500;
        if (r == 'M')
            return 1000;
        return -1;
    }
    static int romanToInt(String str) {
        // Function to convert Roman numeral to decimal
        int res = 0;
        for (int i = 0; i < str.length(); i++) {
            // Getting value of symbol s[i]
            int s1 = value(str.charAt(i));
            if (i + 1 < str.length()) {
                // Getting value of symbol s[i+1]
                int s2 = value(str.charAt(i + 1));
                // Comparing both values
                if (s1 >= s2) {
                    // Value of current symbol is greater
                    // or equal to the next symbol
                    res = res + s1;
                } else {
                    res = res + s2 - s1;
                    i++; // Value of current symbol is
                    // less than the next symbol
                }
            } else {
                res = res + s1;
                i++;
            }
        }
        return res;
    }
    public static void main(String args[]) {
        // Take input from the user
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a Roman numeral: ");
        String str = sc.nextLine();
        // Convert the Roman numeral to decimal and print the result
        int result = romanToInt(str);
        System.out.println("The decimal equivalent of the Roman numeral is: " + result);
    }
}