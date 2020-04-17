class Solution {
    public boolean checkValidString(String s) {
        int mini = 0, maxi = 0;
        for (char ch: s.toCharArray()) {
            if (ch == '(') {
                ++mini;
                ++maxi;
            }
            else if (ch == ')') {
                --mini;
                --maxi;
            }
            else {
                --mini;
                ++maxi;
            }
            if (maxi < 0) return false;
            mini = Math.max(0, mini);
        }
        return mini == 0;
    }
}

public class _678_Valid_Parenthesis_String {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.checkValidString("((*)))"));
    }
}
