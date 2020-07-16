package BinaryTree;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Stack;

//   Implementation of Balanced Binary Search Tree: 
//   1. At most two child nodes 
//   2. Left node is less than parent node, right node is greater than parent node 
//   3. No duplicate value is allowed 
//   4. left and right subtree's heights differ by at most one (recursively apply the same to all subtrees)
public class BinaryTree<K extends Comparable<K>, V> {

    // Node represents each item in tree.
    // It holds key and value pair
    private class Node {
        private K key;
        private V value;
        private Node left;
        private Node right;

        Node(K key, V value) {
            this.key = key;
            this.value = value;
            this.left = null;
            this.right = null;
        }

        // getters and setters use private property names and method overloading for
        // ease of use
        // public getters
        public K key() {
            return this.key;
        }

        public V value() {
            return this.value;
        }

        public Node left() {
            return this.left;
        }

        public Node right() {
            return this.right;
        }

        // public setters
        public void key(K key) {
            this.key = key;
        }

        public void value(V value) {
            this.value = value;
        }

        public void left(Node node) {
            this.left = node;
        }

        public void right(Node node) {
            this.right = node;
        }

    }

    private Node root;

    // constructor
    BinaryTree() {
        this.root = null;
    }

    // public insert method.
    // checks if key exists, returns false if duplicate key found, else call insert
    // recursion and return true.
    public boolean insert(K key, V value) {
        if (search(key, this.root) != null) {
            return false;
        }
        Node newNode = new Node(key, value);
        this.root = insert(newNode, this.root);
        return true;
    }

    // private helper: recursive insert
    private Node insert(Node newNode, Node parent) {
        // BASE CASE: if empty place, return newNode
        if (parent == null) {
            return newNode;
        }
        // if new key < parent key, then insert to parent's left
        // if new key > parent key, then insert to parent's right
        if (newNode.key().compareTo(parent.key()) < 0) {
            parent.left(insert(newNode, parent.left()));
        } else if (newNode.key().compareTo(parent.key()) > 0) {
            parent.right(insert(newNode, parent.right()));
        }
        return parent;
    }

    // public search method
    // given a key, return the value if key exists, else return null
    public V search(K key) {
        return search(key, this.root).value();
    }

    // private helper: recursive search
    // return null if not found, return node if found
    private Node search(K key, Node node) {
        // if traversed out of range, not found
        if (node == null) {
            return null;
        }
        // found the node with key value
        if (key.compareTo(node.key()) == 0) {
            return node;
        }
        // if key is less, recursively search left side
        if (key.compareTo(node.key()) < 0) {
            return search(key, node.left());
        }
        // if key is greater, recursively search right side
        if (key.compareTo(node.key()) > 0) {
            return search(key, node.right());
        }
        return null;
    }

    // public remove method, remove node by key
    // return true if removal is successful, return false if removal fails (key does
    // not exist)
    public boolean remove(K key) {
        Node nodeToDelete = search(key, this.root);
        if (nodeToDelete == null) {
            return false;
        }
        Node parent = findParent(nodeToDelete, this.root);
        // if it's leaf node, simply remove it
        if (nodeToDelete.left() == null && nodeToDelete.right() == null) {
            if (parent == null) {
                this.root = null;
            } else if (parent.left() == nodeToDelete) {
                parent.left(null);
            } else {
                parent.right(null);
            }
        }
        // if it's not leaf node, and has only either child, move all descedents up
        else if (nodeToDelete.left() != null && nodeToDelete.right() == null) {
            if (parent == null) {
                this.root = nodeToDelete.left();
            } else if (parent.left() == nodeToDelete) {
                parent.left(nodeToDelete.left());
            } else {
                parent.right(nodeToDelete.left());
            }
        } else if (nodeToDelete.left() == null && nodeToDelete.right() != null) {
            if (parent == null) {
                this.root = nodeToDelete.right();
            } else if (parent.left() == nodeToDelete) {
                parent.left(nodeToDelete.right());
            } else {
                parent.right(nodeToDelete.right());
            }
        }
        // if nodeToDelete is not leaf and has both children,
        // then take the smallest from right side
        // put that in nodeToDelete's position, then remove nodeToDelete and original
        // smallest node
        else {
            Node minNode = findMin(nodeToDelete.right());
            Node copiedMinNode = new Node(minNode.key(), minNode.value());
            remove(minNode.key());
            copiedMinNode.left(nodeToDelete.left());
            copiedMinNode.right(nodeToDelete.right());
            if (parent == null) {
                this.root = copiedMinNode;
            } else if (parent.left() == nodeToDelete) {
                parent.left(copiedMinNode);
            } else {
                parent.right(copiedMinNode);
            }
        }
        return true;
    }

    // ** Traversals **
    // Include: In-order (left, root, right), Pre-order (root, left, right),
    // Post-order (left, right, root), Level-order (BFS)

    // In-order traversal
    public ArrayList<Node> inOrder() {
        Stack<Node> inOrderStack = new Stack<>();
        ArrayList<Node> arr = new ArrayList<>();
        Node it_ptr;
        // start stack with root node
        inOrderStack.push(this.root);
        while (!inOrderStack.empty()) {
            it_ptr = inOrderStack.peek();
            // traverse as deep to the left
            while (it_ptr.left() != null && !arr.contains(it_ptr.left())) {
                it_ptr = it_ptr.left();
                inOrderStack.push(it_ptr);
            }
            arr.add(inOrderStack.pop());
            // add right child node to top of stack for next iteration
            if (it_ptr.right() != null) {
                inOrderStack.push(it_ptr.right());
            }
        }
        return arr;
    }

    // Pre-order Traversal
    public ArrayList<Node> preOrder() {
        Stack<Node> preOrderStack = new Stack<>();
        ArrayList<Node> arr = new ArrayList<>();
        Node it_ptr;
        // start stack with root node
        preOrderStack.push(this.root);
        while (!preOrderStack.empty()) {
            it_ptr = preOrderStack.peek();
            // add root
            if (!arr.contains(it_ptr)) {
                arr.add(it_ptr);
            }
            // traverse as deep to the left, add to arr as it traverses
            while (it_ptr.left() != null && !arr.contains(it_ptr.left())) {
                it_ptr = it_ptr.left();
                preOrderStack.push(it_ptr);
                // add left
                arr.add(it_ptr);
            }
            preOrderStack.pop();
            // add right child node to top of stack for next iteration
            if (it_ptr.right() != null) {
                preOrderStack.push(it_ptr.right());
            }
        }
        return arr;
    }

    // Post-order Traversal
    public ArrayList<Node> postOrder() {
        Stack<Node> postOrderStack = new Stack<>();
        ArrayList<Node> arr = new ArrayList<>();
        Node it_ptr;
        // start stack with root node
        postOrderStack.push(this.root);
        while (!postOrderStack.empty()) {
            it_ptr = postOrderStack.peek();
            while ((it_ptr.left() != null && !arr.contains(it_ptr.left()))
                    || (it_ptr.right() != null && !arr.contains(it_ptr.right()))) {
                while (it_ptr.left() != null && !arr.contains(it_ptr.left())) {
                    it_ptr = it_ptr.left();
                    postOrderStack.add(it_ptr);
                }
                if (it_ptr.right() != null && !arr.contains(it_ptr.right())) {
                    it_ptr = it_ptr.right();
                    postOrderStack.add(it_ptr);
                }
            }
            arr.add(postOrderStack.pop());
        }
        return arr;
    }

    // Level-order traversal
    public ArrayList<Node> levelOrder() {
        Queue<Node> levelQueue = new ArrayDeque<>();
        ArrayList<Node> arr = new ArrayList<>();
        Node it_ptr;
        // queue start with root node
        levelQueue.add(this.root);
        while (!levelQueue.isEmpty()) {
            it_ptr = levelQueue.peek();
            arr.add(levelQueue.remove());
            if (it_ptr.left() != null) {
                levelQueue.add(it_ptr.left());
            }
            if (it_ptr.right() != null) {
                levelQueue.add(it_ptr.right());
            }
        }
        return arr;
    }

    // print that takes in the array list created by different traversal methods
    public void print(ArrayList<Node> arr) {
        for (Node node : arr) {
            System.out.print("{" + node.key() + ":" + node.value() + "}");
            Node parent = findParent(node, this.root);
            if (parent == null) {
                System.out.println(" (ROOT)");
            } else {
                String leftRight = node.key().compareTo(parent.key()) < 0 ? "LEFT" : "RIGHT";
                System.out.println(" (" + leftRight + " CHILD of {" + parent.key() + ":" + parent.value() + "})");
            }
        }
    }

    private Node findParent(Node child, Node parent) {
        if (child == null || parent == null) {
            return null;
        }
        if (parent.left() == child || parent.right() == child) {
            return parent;
        }
        if (child.key().compareTo(parent.key()) < 0) {
            return findParent(child, parent.left());
        }
        if (child.key().compareTo(parent.key()) > 0) {
            return findParent(child, parent.right());
        }
        return null;
    }

    private Node findMin(Node node) {
        Node min = node;
        while (min.left() != null) {
            min = min.left();
        }
        return min;
    }

}