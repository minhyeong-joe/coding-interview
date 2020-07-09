/*
 * Given a singly linked list, find the node that is at the n-th position from the last node.
 * Assume linked list is singly linked, and does not know the total count.
 */

package LinkedList;

import LinkedList.LinkedList.Node;

public class NthFromLast {
    
    public static void main(String[] args) {
        Integer[] arr = {5, 4, 3, 2, 1, 0};
        LinkedList<Integer> linkedList = new LinkedList<>(arr);

        try {
            int nthLast = nthFromLast(linkedList, 3);
            System.out.println(nthLast);
        } catch (IndexOutOfBoundsException e) {
            System.out.println(e.getMessage());
        }
        
    }

    public static <T> T nthFromLast(LinkedList<T> linkedList, int n) throws IndexOutOfBoundsException {
        // create two ptrs to point to head
        Node<T> resultPtr = linkedList.getIterator();
        Node<T> endCheckPtr = linkedList.getIterator();
        // move endCheckPtr N steps ahead of resultPtr
        for (int i = 0; i < n; i++) {
            endCheckPtr = endCheckPtr.getNext();
            if (endCheckPtr == null) {
                throw new IndexOutOfBoundsException("Given N is outside the range for the given linked list.");
            }
        }
        // move two pointers at the same pace until endCheckPtr hits end of list
        while (endCheckPtr.getNext() != null) {
            resultPtr = resultPtr.getNext();
            endCheckPtr = endCheckPtr.getNext();
        }
        return resultPtr.getData();
    }

}