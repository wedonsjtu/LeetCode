#include <iostream>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m_deg = minutes * 6;
        double h_deg = hour * 30;
        h_deg += (minutes / 2.0);
        double ans;
        if (m_deg > h_deg) {
            ans = m_deg - h_deg;
        }
        else {
            ans = h_deg - m_deg;
        }
        if (ans > 180) {
            ans = 360 - ans;
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().angleClock(12, 30);
    cout << ans << endl;
    return 0;
}
