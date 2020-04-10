class Solution {
    public String removeDuplicates(String S) {
        int p = 0, len = S.length();
        char[] ans = new char[len];
        for (int i=0; i < len; ++i) {
            if (p > 0 && S.charAt(i) == ans[p-1]) --p;
            else {
                ans[p] = S.charAt(i);
                ++p;
            }
        }
        return new String(ans, 0, p);
    }
    
    // public String removeDuplicates(String S) {
    //     if (S.length() <= 1) return S;
    //     Stack<Character> sta = new Stack<>();
    //     for (int i=0; i < S.length(); ++i) {
    //         if (sta.isEmpty()) {
    //             sta.push(S.charAt(i));
    //             continue;
    //         }
    //         if (sta.peek().equals(S.charAt(i))) {
    //             sta.pop();
    //         }
    //         else {
    //             sta.push(S.charAt(i));
    //         }
    //     }
    //     StringBuilder sb = new StringBuilder();
    //     for(char ch : sta) sb.append(ch);
    //     return sb.toString();
    // }
}

public class _1047_Remove_All_Adjacent_Duplicates_In_String {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.removeDuplicates("abcdddc"));
    }
}
