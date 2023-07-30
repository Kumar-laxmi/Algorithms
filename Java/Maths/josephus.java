import java.util.Scanner;

public class josephus {
    
    // Josephus Problem Algorithm:
    // 1. Create an array to represent the circle of people, numbered from 1 to n.
    // 2. Start with an index variable pointing to the first person.
    // 3. Repeat the elimination process until only one person remains:
    //     a. Move the index k-1 steps in a circular manner.
    //     b. Remove the person at the current index by shifting the remaining elements.
    //     c. Update the index to the next position after the elimination, wrapping around if necessary.
    // 4. Return the value of the last remaining person.
    
    public static int JosephusProblem(int n, int k) {
        int[] people = new int[n];
        
        // Initialize the array with people numbered from 1 to n
        for (int i = 0; i < n; i++) {
            people[i] = i + 1;
        }
        
        int index = 0;
        
        // Elimination process
        while (n > 1) {
            // Move the index k-1 steps in a circular manner
            index = (index + k - 1) % n;
            
            // Remove the person at the current index by shifting the remaining elements
            for (int i = index; i < n - 1; i++) {
                people[i] = people[i + 1];
            }
            
            n--;
        }
        
        return people[0];  // Return the value of the last remaining person
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of people in the circle: ");
        int n = scanner.nextInt();
        
        System.out.print("Enter the elimination step size: ");
        int k = scanner.nextInt();
        
        int lastPerson = JosephusProblem(n, k);  // Solve the Josephus Problem
        System.out.println("The last remaining person is at position: " + lastPerson);
        
        scanner.close();
    }
}
