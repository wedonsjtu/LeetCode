import java.util.*;

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        Stack<TreeNode> s = new Stack<>();
        TreeNode topNode = null, lastNodeVisited = null;
        while (!s.empty() || root != null) {
            if (root != null) {
                s.push(root);
                root = root.left;
            }
            else {
                topNode = s.peek();
                if (topNode.right != null && topNode.right != lastNodeVisited) {
                    root = topNode.right;
                }
                else {
                    ans.add(topNode.val);
                    lastNodeVisited = topNode;
                    s.pop();
                }
            }
        }
        return ans;
    }
}

public class _145_Binary_Tree_Postorder_Traversal {
    public static void main(String[] args) {
        String line = "[1,2,3,4,5,6,7,8,9,10]";
        TreeNode root = stringToTreeNode(line);
            
        List<Integer> ret = new Solution().postorderTraversal(root);
        
        String out = integerArrayListToString(ret);
        
        System.out.println(out);
    }

    public static TreeNode stringToTreeNode(String input) {
        input = input.trim();
        input = input.substring(1, input.length() - 1);
        if (input.length() == 0) {
            return null;
        }
    
        String[] parts = input.split(",");
        String item = parts[0];
        TreeNode root = new TreeNode(Integer.parseInt(item));
        Queue<TreeNode> nodeQueue = new LinkedList<>();
        nodeQueue.add(root);
    
        int index = 1;
        while(!nodeQueue.isEmpty()) {
            TreeNode node = nodeQueue.remove();
    
            if (index == parts.length) {
                break;
            }
    
            item = parts[index++];
            item = item.trim();
            if (!item.equals("null")) {
                int leftNumber = Integer.parseInt(item);
                node.left = new TreeNode(leftNumber);
                nodeQueue.add(node.left);
            }
    
            if (index == parts.length) {
                break;
            }
    
            item = parts[index++];
            item = item.trim();
            if (!item.equals("null")) {
                int rightNumber = Integer.parseInt(item);
                node.right = new TreeNode(rightNumber);
                nodeQueue.add(node.right);
            }
        }
        return root;
    }
    
    public static String integerArrayListToString(List<Integer> nums, int length) {
        if (length == 0) {
            return "[]";
        }
    
        String result = "";
        for(int index = 0; index < length; index++) {
            Integer number = nums.get(index);
            result += Integer.toString(number) + ", ";
        }
        return "[" + result.substring(0, result.length() - 2) + "]";
    }
    
    public static String integerArrayListToString(List<Integer> nums) {
        return integerArrayListToString(nums, nums.size());
    }
}
