package LinkedList;

import LinkedList.LinkedList.Node;

public class LinkedListTest {
    
    public static void main(String[] args) {
        // array constructor test
        Integer[] arr = {1, 2, 3, 4, 5};
        LinkedList<Integer> ll = new LinkedList<>(arr);
        System.out.println(ll.toString());

        // iterator test
        Node<Integer> it = ll.getIterator();
        it = it.getNext();
        System.out.println(it.getData());

        // get value by position test
        System.out.println("Value at 'index' 3: " + ll.getDataByPos(3));

        // insert to beginning of list test
        ll.insertAtStart(0);
        System.out.println(ll.toString());

        // append to end of list test
        ll.append(6);
        System.out.println(ll.toString());

        // insert at specific position test
        ll.insert(8, 4);
        System.out.println(ll.toString());

        // remove element test
        try {
            ll.remove(2);
            ll.remove(6);
            ll.remove(0);
            ll.remove(8);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        System.out.println(ll.toString());

        // clear test
        ll.clear();
        System.out.println(ll.toString());
    }

}