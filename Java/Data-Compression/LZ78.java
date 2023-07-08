/*
Written by nuggetbucket54

========== COMPRESSION LOGIC ==========

1. Start with an empty dictionary and an empty input buffer.
2. Read symbols from the input data one at a time.
3. Initialize a prefix as an empty string.
4. Append the current symbol to the prefix.
5. If the prefix is already in the dictionary, update the prefix by
   appending the current symbol and repeat step 5.
6. If the prefix is not in the dictionary, add the prefix to the dictionary with a unique index
   and output the index of the previous prefix and the current symbol.
7. Clear the prefix and repeat from step 4 until all symbols are processed.

========== DECOMPRESSION LOGIC ==========

During decompression, the algorithm uses the dictionary entries to reconstruct the original data.
It reads the index and symbol pairs, retrieves the corresponding phrases from the dictionary, and
outputs them to reconstruct the original data.
*/

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LZ78 {

    private static List<Pair<Integer, Character>> compress(String data) {
        Map<String, Integer> storage = new HashMap<>();
        List<Pair<Integer, Character>> compressed_data = new ArrayList<>();
        StringBuilder current_symbol = new StringBuilder();
        int index = 1;
    
        for (char character : data.toCharArray()) {
            current_symbol.append(character);
            if (!storage.containsKey(current_symbol.toString())) {
                storage.put(current_symbol.toString(), index);
                int previous_index = current_symbol.length() > 1 ? storage.get(current_symbol.substring(0, current_symbol.length() - 1)) : 0;
                compressed_data.add(new Pair<>(previous_index, character));
                index++;
                current_symbol.setLength(0);
            }
        }
    
        return compressed_data;
    }

    private static String decompress(List<Pair<Integer, Character>> data) {
        Map<Integer, String> storage = new HashMap<>();
        StringBuilder decompressed_data = new StringBuilder();
        int index = 1;
    
        for (Pair<Integer, Character> character : data) {
            String phrase = character.getFirst() == 0 ? "" : storage.get(character.getFirst());
            phrase += character.getSecond();
            storage.put(index, phrase);
            decompressed_data.append(phrase);
            index++;
        }
    
        return decompressed_data.toString();
    }

    public static void main(String[] args) {
        String message = "ABBCBCABABCAABCAAB";
        List<Pair<Integer, Character>> compressed_message = compress(message);
        String decompressed_message = decompress(compressed_message);

        System.out.println("Original Message: " + message);
        System.out.print("Compressed Message: ");
        for (Pair<Integer, Character> element : compressed_message) {
            System.out.print("(" + element.getFirst() + ", " + element.getSecond() + "), ");
        }
        System.out.println();
        System.out.println("Decompressed Message: " + decompressed_message);
    }

    private static class Pair<F, S> {
        private final F first;
        private final S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        public F getFirst() {
            return first;
        }

        public S getSecond() {
            return second;
        }
    }
}