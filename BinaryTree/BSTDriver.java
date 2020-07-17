package BinaryTree;

public class BSTDriver {

    public static void main(String[] args) {
        BinaryTree<Integer, String> bst = new BinaryTree<>();
        bst.insert(7, "G");
        bst.insert(6, "F");
        bst.insert(5, "E");
        bst.insert(4, "D");
        bst.insert(3, "C");
        bst.insert(2, "B");
        bst.insert(1, "A");
        System.out.println("Level-Order:");
        bst.print(bst.levelOrder());
        System.out.println();
        bst.remove(6);
        System.out.println("Level-Order:");
        bst.print(bst.levelOrder());
        System.out.println();
        bst.remove(5);
        System.out.println("Level-Order:");
        bst.print(bst.levelOrder());
        System.out.println();
        bst.remove(7);
        System.out.println("Level-Order:");
        bst.print(bst.levelOrder());
        // System.out.println("In-Order:");
        // bst.print(bst.inOrder());
        // System.out.println("Pre-Order:");
        // bst.print(bst.preOrder());
        // System.out.println("Post-Order:");
        // bst.print(bst.postOrder());
    }

}