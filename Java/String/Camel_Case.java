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
class Camel_Case
{
    // Function to remove spaces and convert
    // into camel case
    static String convert(String s)
    {
        // to count spaces
        int cnt= 0;
        int n = s.length();
        char ch[] = s.toCharArray();
        int res_ind = 0;
        for (int i = 0; i < n; i++)
        {
            // check for spaces in the sentence
            if (ch[i] == ' ')
            {
                cnt++;
                // conversion into upper case
                ch[i + 1] = Character.toUpperCase(ch[i + 1]);
                continue;
            }
            // If not space, copy character
            else
                ch[res_ind++] = ch[i];
        }
        // new string will be reduced by the
        // size of spaces in the original string
        return String.valueOf(ch, 0, n - cnt);
    }
    // Main function
    public static void main(String args[])
    {
        String str = "Hii this is Camel Case";
        System.out.println(convert(str));
    }
}