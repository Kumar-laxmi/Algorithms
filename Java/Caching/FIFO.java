import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class FIFO {
    static int pageFaults(int pages[], int n, int capacity) {
        HashSet<Integer> s = new HashSet<>(capacity);
        Queue<Integer> idx = new LinkedList<>();
        int page_faults = 0;
        for (int i = 0; i < n; i++) {
            if (s.size() < capacity) {
                if (!s.contains(pages[i])) {
                    s.add(pages[i]);
                    page_faults++;
                    idx.add(pages[i]);
                }
            } else {
                if (!s.contains(pages[i])) {
                    int val = idx.peek();
                    idx.poll();
                    s.remove(val);
                    s.add(pages[i]);
                    idx.add(pages[i]);
                    page_faults++;
                }
            }
        }

        return page_faults;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of array: ");
        int n = sc.nextInt();
        int pages[] = new int[n];
        System.out.println("Enter the elements of array: ");
        for (int i = 0; i < n; i++) {
            pages[i] = sc.nextInt();
        }
        System.out.println("Enter the capacity: ");
        int capacity = sc.nextInt();
        System.out.println("Answer: ");
        System.out.println(pageFaults(pages, n, capacity));
    }
}
