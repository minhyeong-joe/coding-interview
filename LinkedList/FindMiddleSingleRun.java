/* 
 * Given a singly linked list, print out the middle element without naively iterating list twice.
 * Assume linked list is singly linked, and does not know the total count.
 * If there are two "middle" elements, return the second element.
*/

package LinkedList;

import LinkedList.LinkedList.Node;

public class FindMiddleSingleRun {

    public static void main(String[] args) {
        Character[] arr = {'a', 'b', 'c', 'd', 'e', 'f'};
        LinkedList<Character> linkedList = new LinkedList<>(arr);
        System.out.println(linkedList.toString());

        char mid = findMiddle(linkedList);
        System.out.println(mid);
    }
    
    public static <T> T findMiddle(LinkedList<T> ll) {
        Node<T> findMidPtr = ll.getIterator();
        Node<T> reachEndPtr = ll.getIterator(); 
        // move two pointers at different pace until reachEndPtr reaches end
        while (reachEndPtr != null && reachEndPtr.getNext() != null) {
            findMidPtr = findMidPtr.getNext();
            reachEndPtr = reachEndPtr.getNext().getNext();
        }
        return findMidPtr.getData();
    }

}