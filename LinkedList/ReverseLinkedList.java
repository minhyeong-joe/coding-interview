package LinkedList;

import LinkedList.LinkedList.Node;

/**
 * ReverseLinkedList Using simple solution
 */

public class ReverseLinkedList {

    public static void main(String[] args) {
        Integer[] arr = {4, 3, 2, 1, 0};
        LinkedList<Integer> list = new LinkedList<>(arr);

        LinkedList<Integer> rev = reverse(list);

        System.out.println(rev.toString());
    }

    public static <T> LinkedList<T> reverse(LinkedList<T> list) {
        LinkedList<T> rev = new LinkedList<>();
        Node<T> it = list.getIterator();
        while (it != null) {
            rev.insertAtStart(it.getData());
            it = it.getNext();
        }
        return rev;
    }
    
}