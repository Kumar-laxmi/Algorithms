import java.util.Scanner;

public class CircularLinkedList {
    static class Node{
        int data;
        Node next;

        public Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    static Node head;

    public static void main(String[] args) {
        boolean quit = false;
        Scanner scan = new Scanner(System.in);
        int number;
        menu();
        while(!quit){
            System.out.print("Enter your choice : ");
            int choice = scan.nextInt();
            switch (choice){
                case 9 -> quit = true;
                case 1 -> menu();
                case 2 -> {
                    System.out.print("Enter data : ");
                    number = scan.nextInt();
                    addNodeAtBeginning(number);
                }
                case 3 -> {
                    System.out.print("Enter data : ");
                    number = scan.nextInt();
                    addNodeAtEnd(number);
                }
                case 4 -> {
                    System.out.print("Enter data : ");
                    number = scan.nextInt();
                    System.out.print("Enter key to add new node after node : ");
                    int key = scan.nextInt();
                    addNodeAfter(key , number);
                }
                case 5 -> deleteHead();
                case 6 -> deleteLastNode();
                case 7 -> {
                    System.out.print("Enter key to delete : ");
                    number = scan.nextInt();
                    deleteNodeByData(number);
                }
                case 8 -> printList();
            }
        }
    }
    static void menu(){
        System.out.println("1. To print operations");
        System.out.println("2. To add node at beginning");
        System.out.println("3. To add node at end");
        System.out.println("4. To add node after node");
        System.out.println("5. To delete from beginning");
        System.out.println("6. To delete from end");
        System.out.println("7. To delete by value");
        System.out.println("8. To print circular list");
        System.out.println("9. To exit");

    }
    static void addNodeAtEnd(int data){
        Node node = new Node(data);

        if(head == null){
            head = node;
        } else {
            Node temp = head;
            while(temp.next != head){
                temp = temp.next;
            }
            temp.next = node;
        }
        node.next = head;

        System.out.println(data + " added in list");
    }
    static void addNodeAtBeginning(int data){
        Node node = new Node(data);

        if(head == null){
            head = node;
            head.next = head;
        } else {
            Node temp = head;
            while(temp.next != head){
                temp = temp.next;
            }
            temp.next = node;
            node.next = head;
            head = node;
        }
        System.out.println(data + " added in list");
    }

    static void addNodeAfter(int key , int data){
        Node node = new Node(data);

        if(head == null) {
            addNodeAtBeginning(data);
        } else {
            Node temp = head;

            while(temp.next != head){
                if(temp.data == key){
                    node.next = temp.next;
                    temp.next = node;
                }
                temp = temp.next;
            }
        }
        System.out.println(data + " added in list");
    }

    static void deleteHead(){
        Node temp = head;
        if(head.next == head){
            head = null;
            return;
        }
        while(temp.next != head){
            temp = temp.next;
        }
        temp.next = head.next;
        head = head.next;

        System.out.println("head deleted");
    }

    static void deleteLastNode(){
        Node temp = head;
        while(temp.next.next != head){
            temp = temp.next;
        }
        temp.next = head;
        System.out.println("Tail deleted");
    }

    static void deleteNodeByData(int data){
        Node temp = head;

        while(temp.next != head){
            if(temp.next.data == data){
                temp.next = temp.next.next;
            }
            temp = temp.next;
        }
        System.out.println("Node with data " + data + "deleted");
    }
    static void printList(){
        Node temp = head;
        if(head == null){
            System.out.println("Empty list");
            return;
        }
        while(temp.next != head){
            System.out.print(temp.data + "->");
            temp = temp.next;
        }
        System.out.println(temp.data);
    }
}
