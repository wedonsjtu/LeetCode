// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return root;
        }
        Node left_node = root;
        while (left_node.left != null) {
            Node tmp = left_node;
            while (tmp != null) {
                tmp.left.next = tmp.right;
                if (tmp.next != null) tmp.right.next = tmp.next.left;
                tmp = tmp.next;
            }
            left_node = left_node.left;
        }
        return root;
    }
}

// public class _116_Populating_Next_Right_Pointers_in_Each_Node {
//     public static void main(String[] args) {
//         Solution s = new Solution();

//     }
// }
