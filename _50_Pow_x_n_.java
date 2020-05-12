class Solution {
    public double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == Integer.MIN_VALUE) {
            x = x * x;
            n /= 2;
        }
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        double ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) ans *= x;
            x = x * x;
            n /= 2;
        }
        return ans;
    }
}

public class _50_Pow_x_n_ {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.myPow(2.0, 11));
    }
}
