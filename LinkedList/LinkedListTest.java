package LinkedList;

import LinkedList.LinkedList.Node;

public class LinkedListTest {
    
    public static void main(String[] args) {
        Integer[] arr = {1, 2, 3, 4, 5};
        LinkedList<Integer> ll = new LinkedList<>(arr);
        System.out.println(ll.toString());

        Node<Integer> it = ll.getIterator();
        it = it.getNext();
        System.out.println(it.getData());
    }

}