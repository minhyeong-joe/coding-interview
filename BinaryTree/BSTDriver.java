package BinaryTree;

public class BSTDriver {

    public static void main(String[] args) {
        BinaryTree<Integer, String> bst = new BinaryTree<>();
        bst.insert(3, "A");
        bst.insert(8, "B");
        bst.insert(1, "C");
        bst.insert(6, "D");
        bst.insert(2, "E");
        bst.insert(7, "F");
        bst.insert(4, "G");
        bst.insert(9, "H");
        bst.insert(5, "I");
        System.out.println("Level-Order:");
        bst.print(bst.levelOrder());
        System.out.println("In-Order:");
        bst.print(bst.inOrder());
        System.out.println("Pre-Order:");
        bst.print(bst.preOrder());
        System.out.println("Post-Order:");
        bst.print(bst.postOrder());
    }

}