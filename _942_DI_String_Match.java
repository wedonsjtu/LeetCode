import java.util.Arrays;

class Solution {
    public int[] diStringMatch(String S) {
        int _min = 0, _max = S.length();
        int[] ans = new int[_max+1];
        int i=0;
        for (; i < S.length(); ++i) {
            if (S.charAt(i) == 'I') {
                ans[i] = _min++;
            }
            else {
                ans[i] = _max--;
            }
        }
        ans[i] = _max;
        return ans;
    }
}

public class _942_DI_String_Match {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(Arrays.toString(s.diStringMatch("DDIIIDD")));
    }
}
