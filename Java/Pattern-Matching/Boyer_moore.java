/*------------------------------------------------INTRODUCTION-------------------------------------------------------------------------*/
/*Boyer-Moore-Horspool is an algorithm for finding substrings into strings. This algorithm compares each characters of substring to find 
a word or the same characters into the string from right to left. When characters do not match, the search jumps to the next matching 
position in the pattern by the value indicated in the Bad Match Table.
value is calculated using 
"value=length(substring)-index(last occurance)-1."

The Bad Match Table indicates how many jumps should it move from the current position to the next.*/

/*----------------------------------------------ALGORITHM-----------------------------------------------------------------------------
1.first it finds out the lenght of both the strings.
2.bad match table is prepared using the value formula for substring and it include characters only once no repeated element is 
  considered elements out of the substring that are present in main string are considered under *.
3.now it compares each char of substring from right to left with parent string if not found moves from the current position to next 
  by the corresponding value of that character in bad match table.
4.after all successful comparisions the index is returned at which is was matched.
*/

import java.util.ArrayList;
import java.util.List;

public class Boyer_moore{
  //method for boyer moore algorithm
  public static List<Integer> boyerMooreHorspool(String text, String pattern) {
    //arraylist is created to strore the indexeis if occurence
    List<Integer> occurrences = new ArrayList<>();
    int textLength = text.length();
    int patternLength = pattern.length();

    // If the pattern is empty, return an empty occurrences list
    if (patternLength == 0) {
        return occurrences;
    }
// Preprocessing: Generate the bad character shift table
    List<Integer> shiftTable = new ArrayList<>(256);
    for (int i = 0; i < 256; i++) {
        shiftTable.add(patternLength);
    }
//adding shift values
    for (int i = 0; i < patternLength - 1; i++) {
        shiftTable.set(pattern.charAt(i), patternLength - 1 - i);
    }

    int i = 0;
    while (i <= textLength - patternLength) {
        int j = patternLength - 1;
// Compare the pattern characters from right to left with the corresponding text characters
        while (j >= 0 && pattern.charAt(j) == text.charAt(i + j)) {
            j--;
        }
 // If a match is found, record the occurrence and move to the next position in the text
        if (j == -1) {
            occurrences.add(i);
            i++;
        } else {
           // Move i by the shift amount based on the last character of the current window by updating the value of shift
            int shift = shiftTable.get(text.charAt(i + patternLength - 1));
            i += shift;
        }
    }

    return occurrences;
}

public static void main(String[] args) {
    String text = "ABABDABACDABABCABAB";
    String pattern = "ABABCABAB";
// Call the Boyer-Moore-Horspool function to find occurrences
    List<Integer> occurrences = boyerMooreHorspool(text, pattern);

// Print the indices where the pattern occurs in the text
    System.out.print("Occurrences found at indices: ");
    for (int i : occurrences) {
        System.out.print(i + " ");
    }
    System.out.println();
}
}
