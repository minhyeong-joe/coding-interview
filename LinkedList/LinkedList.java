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

    // getHead (to iterate)
    public Node<T> getIterator() {
        return this.head;
    }

    @Override
    public String toString() {
        Node<T> it_ptr = this.head;
        StringBuilder TO_STRING = new StringBuilder();
        while(it_ptr != null) {
            TO_STRING.append(it_ptr.data.toString() + " ");
            it_ptr = it_ptr.next;
        }
        return TO_STRING.toString();
    }

}