package BinaryTree;

/**
 * BinaryTree Technically Binary Tree is family of data structures and this is
 * an implementation of Binary Search Tree The elements are organized in a way
 * such that: 1. left node is less than parent node 2. right node is greater
 * than parent node 3. No duplicate value is allowed
 */
public class BinaryTree<T extends Comparable<T>> {

    /**
     * Node represents each item within the tree
     */
    class Node<T extends Comparable<T>> {
        private T value;
        private Node<T> left;
        private Node<T> right;

        Node(T value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }

        public T getValue() {
            return this.value;
        }

        public void setValue(T value) {
            this.value = value;
        }

        public Node<T> getLeft() {
            return this.left;
        }

        public Node<T> getRight() {
            return this.right;
        }

        public void setLeft(Node<T> node) {
            this.left = node;
        }

        public void setRight(Node<T> node) {
            this.right = node;
        }
    }

    private Node<T> root;

    BinaryTree() {
        this.root = null;
    }

    /**
     * insertion Start from root, recursively find appropriate place for newValue by
     * comparing values
     * 
     * @param value New value to be inserted into Binary Tree
     */
    public void insert(T value) {
        this.root = insert(value, this.root);
    }

    /**
     * private helper recursive function for Insertion
     * 
     * @param value   New value to be inserted into Binary Tree
     * @param current Reference to current node to compare value to
     * @return Node<T> Root with new inserted node
     */
    private Node<T> insert(T value, Node<T> current) {
        if (current == null) {
            return new Node<T>(value);
        }
        if (value.compareTo(current.getValue()) < 0) {
            current.setLeft(insert(value, current.getLeft()));
        } else if (value.compareTo(current.getValue()) > 0) {
            current.setRight(insert(value, current.getRight()));
        }
        return current;
    }

    /**
     * Search the target value within tree and return the node
     * 
     * @param target target value
     * @return Node<T>
     * @return null if not found
     */
    public Node<T> search(T target) {
        return search(target, this.root);
    }

    /**
     * Private helper recursive function for search
     * 
     * @param target target value
     * @param node   current compared node reference
     * @return Node<T>
     */
    private Node<T> search(T target, Node<T> node) {
        if (node == null) {
            return null;
        }
        if (target.compareTo(node.getValue()) == 0) {
            return node;
        }
        if (target.compareTo(node.getValue()) < 0) {
            return search(target, node.getLeft());
        }
        if (target.compareTo(node.getValue()) > 0) {
            return search(target, node.getRight());
        }
        return null;
    }

    /**
     * Remove the target value from the tree
     * 
     * @param target target value to remove from tree
     */
    public void remove(T target) {
        Node<T> nodeToDelete = search(target);
        if (nodeToDelete == null) {
            return;
        }
        Node<T> parent = findParent(nodeToDelete, this.root);
        // if it's leaf node, simply remove it
        if (nodeToDelete.getLeft() == null && nodeToDelete.getRight() == null) {
            if (parent == null) {
                this.root = null;
                return;
            }
            if (parent.getLeft() == nodeToDelete) {
                parent.setLeft(null);
            } else {
                parent.setRight(null);
            }
        }
        // if it's not leaf node, and has only either child, move all descedents up
        else if (nodeToDelete.getLeft() != null && nodeToDelete.getRight() == null) {
            if (parent == null) {
                this.root = nodeToDelete.getLeft();
                return;
            }
            if (parent.getLeft() == nodeToDelete) {
                parent.setLeft(nodeToDelete.getLeft());
            } else {
                parent.setRight(nodeToDelete.getLeft());
            }
        } else if (nodeToDelete.getLeft() == null && nodeToDelete.getRight() != null) {
            if (parent == null) {
                this.root = nodeToDelete.getRight();
                return;
            }
            if (parent.getLeft() == nodeToDelete) {
                parent.setLeft(nodeToDelete.getRight());
            } else {
                parent.setRight(nodeToDelete.getRight());
            }
        }
        // if nodeToDelete is not leaf and has both children, then take the smallest
        // from right side
        else {
            T min = findMin(nodeToDelete.getRight());
            // make a copy of this node, and delete the one in the node
            Node<T> minNode = new Node<T>(min);
            remove(min);
            minNode.setLeft(nodeToDelete.getLeft());
            minNode.setRight(nodeToDelete.getRight());
            if (parent == null) {
                this.root = minNode;
                return;
            }
            if (parent.getLeft() == nodeToDelete) {
                parent.setLeft(minNode);
            } else {
                parent.setRight(minNode);
            }
        }
    }

    /**
     * Simple print
     */
    public void print() {
        System.out.print(print(this.root, new StringBuilder(""), null, null));
    }

    /**
     * Private helper recursion for print()
     * 
     * @param current Current node
     * @param sb      StringBuilder to accumulate string output
     * @param parent  parent node for display purpose
     * @param child   left or right child for display purpose
     * @return StringBuilder final string output
     */
    private StringBuilder print(Node<T> current, StringBuilder sb, T parent, String child) {
        if (current != null) {
            sb.append(current.getValue());
            if (parent != null) {
                sb.append(" (" + child + " child of " + parent + ")");
            } else {
                sb.append(" (ROOT)");
            }
            sb.append("\n");

            print(current.getLeft(), sb, current.getValue(), "left");
            print(current.getRight(), sb, current.getValue(), "right");
        }
        return sb;
    }

    public T findParent(T target) {
        Node<T> child = search(target);
        Node<T> parent = findParent(child, this.root);
        return parent == null ? null : parent.getValue();
    }

    private Node<T> findParent(Node<T> child, Node<T> parent) {
        if (child == null || parent == null) {
            return null;
        }
        if (parent.getLeft() == child || parent.getRight() == child) {
            return parent;
        }
        if (child.getValue().compareTo(parent.getValue()) < 0) {
            return findParent(child, parent.getLeft());
        }
        if (child.getValue().compareTo(parent.getValue()) > 0) {
            return findParent(child, parent.getRight());
        }
        return null;
    }

    private T findMin(Node<T> node) {
        T min = node.getValue();
        while (node.getLeft() != null) {
            min = node.getLeft().getValue();
            node = node.getLeft();
        }
        return min;
    }

}