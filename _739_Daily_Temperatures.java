import java.util.Arrays;

class Solution {
    public int[] dailyTemperatures(int[] T) {
        int len = T.length;
        int[] ans = new int[len];
        int right_max = Integer.MIN_VALUE;
        int tmp;
        for (int i=len-1; i >= 0; --i) {
            if (right_max <= T[i]) {
                right_max = T[i];
            }
            else {
                tmp = 1;
                while (T[i+tmp] <= T[i]) {
                    tmp += ans[i+tmp];
                }
                ans[i] = tmp;
            }
        }
        return ans;
    }
}

public class _739_Daily_Temperatures {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] t = {73, 74, 75, 71, 69, 72, 76, 73};
        System.out.println(Arrays.toString(s.dailyTemperatures(t)));
    }
}
