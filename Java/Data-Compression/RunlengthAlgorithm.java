public class RunLengthAlgorithm {
    
    public static String runLengthEncode(String input) {
        StringBuilder output = new StringBuilder(); // Initialize an empty output sequence
        
        int count = 1; // Initialize count to 1 for the first element
        
        for (int i = 0; i < input.length(); i++) {
            if (i + 1 < input.length() && input.charAt(i) == input.charAt(i + 1)) {
                // If the current element is the same as the next element, increment the count
                count++;
            } else {
                // If the current element is different from the next element, add it to the output sequence
                output.append(input.charAt(i));
                output.append(count);
                
                count = 1; // Reset the count for the next element
            }
        }
        
        return output.toString();
    }
    
    public static void main(String[] args) {
        String input = "AAAABBBCCDAA";
        String encoded = runLengthEncode(input);
        
        System.out.println("Encoded sequence: " + encoded);
    }
}
