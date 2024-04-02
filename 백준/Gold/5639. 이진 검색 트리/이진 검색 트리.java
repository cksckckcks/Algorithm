import java.io.*;

public class Main {
    static class BinarySearchTree {
        int node;
        BinarySearchTree left, right;

        BinarySearchTree() {}
        BinarySearchTree(int n) {
            node = n;
        }
    }

    static void insertNode(BinarySearchTree bst, int n) {
        if (bst.node > n) {
            if (bst.left == null)
                bst.left = new BinarySearchTree(n);
            else
                insertNode(bst.left, n);
        }
        else if (bst.right == null)
            bst.right = new BinarySearchTree(n);
        else
            insertNode(bst.right, n);
    }

    static void postfix(BinarySearchTree bst) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        if (bst.left != null)
            postfix(bst.left);
        if (bst.right != null)
            postfix(bst.right);

        bw.write(bst.node + "\n");

        bw.flush();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        BinarySearchTree root = new BinarySearchTree();

        String input = bf.readLine();
        root.node = Integer.parseInt(input);

        while(true) {
            input = bf.readLine();

            if (input == null || input.isEmpty())
                break;

            int n = Integer.parseInt(input);
            insertNode(root, n);
        }

        postfix(root);

        bf.close();
    }
}