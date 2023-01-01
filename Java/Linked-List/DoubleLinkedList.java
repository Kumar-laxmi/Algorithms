// Generic implementation of Double Linked List
public class DoubleLinkedList<T> {
    // internal node class
    private class Node<T> {
        T data;
        Node<T> next, prev;

        public Node(T data, Node<T> prev, Node<T> next) {
            this.data = data;
            this.next = next;
            this.prev = prev;
        }
    }

    private int size = 0;
    private Node<T> head = null;
    private Node<T> tail = null;


    // method to clear the doubly linked list
    public void clear() {

        //"trav" is the node used here for traversal of the linked list
        Node<T> trav = head;
        while (trav != null) {
            Node<T> next = trav.next;
            trav.prev = trav.next = null;
            trav.data = null;
            trav = next;
        }
        head = tail = trav = null;
        size = 0;
    }

    // returns the current size of the doubly linked list
    public int size() {
        return size;
    }

    // check if the doubly linked list is empty of not
    public boolean isEmpty() {
        return size() == 0;
    }

    // adds a node to the last
    public void add(T item) {
        addLast(item);
    }

    // adds a node to beginning
    @SuppressWarnings("unchecked")
    public void addFirst(T item) {
        if (isEmpty()) {
            head = new Node(item, null, null);
            tail = head;
        } else {
            head.prev = new Node(item, null, head);
            head = head.prev;
        }
        size++;
    }

    // adds a node to the last
    @SuppressWarnings("unchecked")
    public void addLast(T item) {
        if (isEmpty()) {
            head = new Node(item, null, null);
            tail = head;
        } else {
            tail.next = new Node(item, tail, null);
            tail = tail.next;
        }
        size++;
    }

    // returns the first data in the doubly linked list
    public T peekFirst() {
        if (isEmpty())
            throw new RuntimeException("Empty List");
        return head.data;
    }

    // returns the last data in the doubly linked list
    public T peekLast() {
        if (isEmpty())
            throw new RuntimeException("Empty List");
        return tail.data;
    }

    // removes the first element
    public T removeFirst() {
        if (isEmpty())
            throw new RuntimeException("Empty List");

        T temp = head.data;
        head = head.next;
        size--;

        if (isEmpty())
            tail = null;

        else
            head.prev = null;

        return temp;
    }

    // removes the last element
    public T removeLast() {
        if (isEmpty())
            throw new RuntimeException("Empty List");

        T temp = tail.data;
        tail = tail.prev;
        size--;

        if (isEmpty())
            head = null;
        else
            tail.next = null;

        return temp;
    }

    // a private method for maintaining the list internally
    private T remove(Node<T> node) {
        if (node.prev == null)
            return removeFirst();
        if (node.next == null)
            return removeLast();

        node.next.prev = node.prev;
        node.prev.next = node.next;

        T temp = node.data;

        node.data = null;
        node = node.prev = node.next = null;

        size--;

        return temp;
    }

    // removes the element of a particular index
    public T removeAt(int index) {
        if (index < 0 || index >= size)
            throw new IllegalArgumentException();

        int i;
        Node<T> trav;

        if (index < size() / 2) {
            for (i = 0, trav = head; i != index; i++)
                trav = trav.next;
        } else {
            for (i = size() - 1, trav = tail; i != index; i--)
                trav = trav.prev;
        }

        return remove(trav);
    }

    // remove a particular element
    public boolean remove(Object obj) {
        Node<T> trav = head;
        if (obj == null) {
            for (trav = head; trav != null; trav = trav.next) {
                if (trav.data == null) {
                    remove(trav);
                    return true;
                }
            }
        } else {
            for (trav = head; trav != null; trav = trav.next) {
                if (obj.equals(trav.data)) {
                    remove(trav);
                    return true;
                }
            }
        }
        return false;
    }

    // returns the index of a particular element
    public int indexOf(Object obj) {
        int index = 0;
        Node<T> trav = head;

        if (obj == null) {
            for (trav = head; trav != null; trav = trav.next, index++) {
                if (trav.data == null) {
                    remove(trav);
                    return index;
                }
            }
        } else {
            for (trav = head; trav != null; trav = trav.next, index++) {
                if (obj.equals(trav.data)) {
                    remove(trav);
                    return index;
                }
            }
        }
        return -1;
    }

    // checks if the particular element is present
    public boolean contains(Object obj) {
        return indexOf(obj) != -1;
    }

    // prints the doubly linked list as a string
    public String asString() {
        String str = "[";
        Node<T> trav = head;
        while (trav.next != null) {
            str += trav.data + ", ";
            trav = trav.next;
        }
        str += trav.data + "]";
        return str;
    }

    // testing the above code
    public static void main(String[] args) {
        DoubleLinkedList<Integer> doubleLinkedList = new DoubleLinkedList<>();
        doubleLinkedList.add(1);
        doubleLinkedList.add(2);
        doubleLinkedList.add(3);
        doubleLinkedList.add(4);

        // printing the double linked list
        System.out.println("Double Linked List: " + doubleLinkedList.asString());

        // size of the double linked list
        System.out.println("Size: " + doubleLinkedList.size());

        // first element
        System.out.println("first element: " + doubleLinkedList.peekFirst());

        // last element
        System.out.println("last element: " + doubleLinkedList.peekLast());

        // removing last element
        System.out.println("last element removed, " + doubleLinkedList.removeLast() + ", " + doubleLinkedList.asString());

        // remove first element
        System.out.println("first element removed, " + doubleLinkedList.removeFirst() + ", " + doubleLinkedList.asString());
    }
}