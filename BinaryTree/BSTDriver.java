package BinaryTree;

public class BSTDriver {

    public static void main(String[] args) {
        BinaryTree<Integer> bst = new BinaryTree<>();
        bst.insert(3);
        bst.insert(8);
        bst.insert(1);
        bst.insert(6);
        bst.insert(2);
        bst.insert(7);
        bst.insert(4);
        bst.insert(9);
        bst.insert(5);
        bst.print();

        bst.remove(3);
        bst.print();
    }

}