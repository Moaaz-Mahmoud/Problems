import java.util.*;
import java.io.*;

class Node {
    Node left;
    Node right;
    int data;
    
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Solution {

	enum Direction {LEFT, RIGHT}
    public static Node lca(Node root, int v1, int v2) {
        Direction dir1, dir2;
        if(v1 < root.data)
            dir1 = Direction.LEFT;
        else if(v1 > root.data)
            dir1 = Direction.RIGHT;
        else
            return root;
        if(v2 < root.data)
            dir2 = Direction.LEFT;
        else if(v2 > root.data)
            dir2 = Direction.RIGHT;
        else
            return root;
            
        if(dir1 != dir2)
            return root;
        if(dir1 == Direction.LEFT)
            return lca(root.left, v1, v2);
        else
            return lca(root.right, v1, v2);
    }

	public static Node insert(Node root, int data) {
        if(root == null) {
            return new Node(data);
        } else {
            Node cur;
            if(data <= root.data) {
                cur = insert(root.left, data);
                root.left = cur;
            } else {
                cur = insert(root.right, data);
                root.right = cur;
            }
            return root;
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        Node root = null;
        while(t-- > 0) {
            int data = scan.nextInt();
            root = insert(root, data);
        }
      	int v1 = scan.nextInt();
      	int v2 = scan.nextInt();
        scan.close();
        Node ans = lca(root,v1,v2);
        System.out.println(ans.data);
    }	
}
