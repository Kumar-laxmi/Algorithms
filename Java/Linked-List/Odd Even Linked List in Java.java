/*author: Abhay saxena
Github username: YourFatherDumb
Topic: Odd Even Linked list in java
About: Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
For eg:-
Input :- head =[8,4,7,2,9]
Output :- [8,7,9,4,2]*/

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

class Main {
    public static ListNode oddEvenLinkedList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode oddDummy = new ListNode(0);
        ListNode evenDummy = new ListNode(0);

        ListNode oddCurr = oddDummy;
        ListNode evenCurr = evenDummy;

        boolean isOdd = true;

        while (head != null) {
            if (isOdd) {
                oddCurr.next = head;
                oddCurr = oddCurr.next;
            } else {
                evenCurr.next = head;
                evenCurr = evenCurr.next;
            }

            isOdd = !isOdd;
            head = head.next;
        }

        oddCurr.next = evenDummy.next;
        evenCurr.next = null;

        return oddDummy.next;
    }

    public static ListNode createLinkedList(int[] nums) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;

        for (int num : nums) {
            curr.next = new ListNode(num);
            curr = curr.next;
        }

        return dummy.next;
    }

    public static void printLinkedList(ListNode head) {
        ListNode curr = head;

        while (curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the values of the linked list (space-separated): ");
        String[] input = scanner.nextLine().split(" ");
        int[] nums = new int[input.length];

        for (int i = 0; i < input.length; i++) {
            nums[i] = Integer.parseInt(input[i]);
        }

        ListNode head = createLinkedList(nums);
        ListNode reorderedList = oddEvenLinkedList(head);

        System.out.println("Reordered List:");
        printLinkedList(reorderedList);
    }
}
