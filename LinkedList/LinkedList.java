/*
 * Singly Linked List implementation to avoid using built-in linked list.
 * Implemented the basic functionalities only
 */

package LinkedList;

public class LinkedList<T> {
    
    // Node
    static class Node<T> {
        private T data;
        private Node next;
        
        Node(T data) {
            this.data = data;
            this.next = null;
        }
        Node(T data, Node next) {
            this.data = data;
            this.next = next;
        }

        public T getData() {
            return this.data;
        }

        public Node getNext() {
            return this.next;
        }
    }
    
    private Node<T> head;
    
    // constructor
    LinkedList() {
        this.head = null;
    }

    // array constructor
    LinkedList(T[] arr) {
        if (arr.length < 1) {
            this.head = null; 
            return;
        }
        Node<T> newNode = new Node<>(arr[0]);
        this.head = newNode;
        Node<T> it_ptr = this.head;
        for (int i = 1; i < arr.length; i++) {
            newNode = new Node<>(arr[i]);
            it_ptr.next = newNode;
            it_ptr = newNode;
        }
    }

    // @desc    getHead (to iterate)
    // @usage   Node<T> iterator = linkedList.getIterator();
    //          iterator.getNext(); iterator.getData(); ...etc 
    public Node<T> getIterator() {
        return this.head;
    }

    // @desc    get data of given position
    public T getDataByPos(int pos) {
        Node<T> nodeAtPos = nthNode(pos);
        if (nodeAtPos == null) {
            throw new IndexOutOfBoundsException("Out Of Range");
        }
        return nodeAtPos.data;
    }

    // @desc    insert the given value in the start of list
    public void insertAtStart(T data) {
        Node<T> newNode = new Node<>(data, this.head);
        this.head = newNode;
    }

    // @desc    append the given value at the end of list
    public void append(T data) {
        Node<T> newNode = new Node<>(data);
        // if list is empty
        if (this.head == null) {
            this.head = newNode;
            return;
        }
        Node<T> it_ptr = this.head;
        while (it_ptr.next != null) {
            it_ptr = it_ptr.next;
        }
        it_ptr.next = newNode;
    }

    // @desc    insert at given position
    public void insert(T data, int pos) {
        if (pos == 0) {
            insertAtStart(data);
            return;
        }
        Node<T> prevPtr = nthNode(pos-1);
        // if list is not long enough, simply append to end
        if (prevPtr == null) {
            append(data);
            return;
        }
        Node<T> newNode = new Node<>(data, prevPtr.next);
        prevPtr.next = newNode;
    }

    // @desc    remove a node from a list at given position
    public void remove(int pos) {
        Node<T> nodeToDelete = nthNode(pos);
        // if position is not within linked list range
        if (nodeToDelete == null) {
            throw new IndexOutOfBoundsException("Out Of Range");
        }
        // if removing head
        if (pos == 0) {
            this.head = this.head.next;
        } else {
            Node<T> prevNode = nthNode(pos-1);
            prevNode.next = nodeToDelete.next;
        }
    }

    // @desc    clear the list
    public void clear() {
        this.head = null;
    }

    @Override
    public String toString() {
        Node<T> it_ptr = this.head;
        StringBuilder TO_STRING = new StringBuilder("{");
        while(it_ptr != null) {
            TO_STRING.append(it_ptr.data.toString());
            if (it_ptr.next != null) {
                TO_STRING.append(" -> ");
            }
            it_ptr = it_ptr.next;
        }
        TO_STRING.append("}");
        return TO_STRING.toString();
    }

    // HELPER function to iterate to Nth position
    private Node<T> nthNode(int pos) {
        Node<T> it_ptr = this.head;
        for (int i = 0; i < pos; i++) {
            if (it_ptr == null) {
                return it_ptr;
            }
            it_ptr = it_ptr.next;
        }
        return it_ptr;
    }

}