import java.util.Scanner;

public class LinearProbing {
    private static final int MAX = 100;

    private static int create(int num) {
        int key = num % 100;
        return key;
    }

    private static void linearProb(int[] a, int key, int num) {
        int flag, i, count = 0;
        flag = 0;

        if (a[key] == -1) {
            a[key] = num;
        } else {
            System.out.println("\nCollision Detected...!!!\n");
            i = 0;

            while (i < MAX) {
                if (a[i] != -1)
                    count++;
                i++;
            }

            System.out.println("Collision avoided successfully using LINEAR PROBING\n");

            if (count == MAX) {
                System.out.println("\nHash table is full");
                display(a);
                System.exit(1);
            }

            for (i = key + 1; i < MAX; i++) {
                if (a[i] == -1) {
                    a[i] = num;
                    flag = 1;
                    break;
                }
            }

            i = 0;

            while ((i < key) && (flag == 0)) {
                if (a[i] == -1) {
                    a[i] = num;
                    flag = 1;
                    break;
                }
                i++;
            }
        }
    }

    private static void display(int[] a) {
        Scanner scanner = new Scanner(System.in);
        int i, choice;

        System.out.println("1.Display ALL\n2.Filtered Display\n");
        choice = scanner.nextInt();

        if (choice == 1) {
            System.out.println("\nThe hash table is\n");
            for (i = 0; i < MAX; i++)
                System.out.println(i + " " + a[i]);
        } else {
            System.out.println("\nThe hash table is\n");
            for (i = 0; i < MAX; i++) {
                if (a[i] != -1) {
                    System.out.println(i + " " + a[i]);
                    continue;
                }
            }
        }
        scanner.close();
    }

    public static void main(String[] args) {
        int[] a = new int[MAX];
        int num, key, i;
        int ans = 1;

        System.out.println("Collision handling by linear probing : \n");

        for (i = 0; i < MAX; i++) {
            a[i] = -1;
        }

        Scanner scanner = new Scanner(System.in);

        do {
            System.out.println("\nEnter the data");
            num = scanner.nextInt();
            key = create(num);
            linearProb(a, key, num);
            System.out.println("\nDo you wish to continue? (1/0)");
            ans = scanner.nextInt();
        } while (ans != 0);

        display(a);

        scanner.close();
    }
}
