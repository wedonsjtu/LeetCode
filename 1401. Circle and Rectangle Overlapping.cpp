#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
    //     // 圆心在矩形中
    //     // 矩形心在圆中
    //     // 圆心与四条线段的距离
    //     if (x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2) return true;
    //     double x_r_c = (double)(x1 + x2) / 2, y_r_c = (double)(y1 + y2) / 2;
    //     if ((x_center - x_r_c) * (x_center - x_r_c) + (y_center - y_r_c) * (y_center - y_r_c) <= radius * radius) return true;
    //     return overlap(radius, x_center, y_center, x1, y1, x2, y1) ||
    //     overlap(radius, x_center, y_center, x2, y1, x2, y2) ||
    //     overlap(radius, x_center, y_center, x1, y2, x2, y2) ||
    //     overlap(radius, x_center, y_center, x1, y2, x1, y1);
    // }

    // bool overlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
    //     if (y1 == y2) {
    //         int y_abs = y1 - y_center;
    //         if (y_abs < 0) y_abs = -y_abs;
    //         if (y_abs > radius) return false;
    //         if ((x_center >= x1 && x_center <= x2)||(x_center >= x2 && x_center <= x1)) return true;
    //         double d1 = (x_center - x1)*(x_center-x1) + (y_center - y1)*(y_center-y1);
    //         double d2 = (x_center - x2)*(x_center-x2) + (y_center - y2)*(y_center-y2);
    //         radius *= radius;
    //         return (d1 > radius && d2 < radius) || (d1 < radius && d2 > radius);
    //     }
    //     if (x1 == x2) {
    //         int x_abs = x1 - x_center;
    //         if (x_abs < 0) x_abs = -x_abs;
    //         if (x_abs > radius) return false;
    //         if ((y_center >= y1 && y_center <= y2)||(y_center >= y2 && y_center <= y1)) return true;
    //         double d1 = (x_center - x1)*(x_center-x1) + (y_center - y1)*(y_center-y1);
    //         double d2 = (x_center - x2)*(x_center-x2) + (y_center - y2)*(y_center-y2);
    //         radius *= radius;
    //         return (d1 > radius && d2 < radius) || (d1 < radius && d2 > radius);
    //     }
    //     return true;
    // }

    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if (x1 <= x_center && x_center <= x2 && y1 <= y_center && y_center <= y2) return true;
        if (isInCircle(radius, x_center, y_center, x1, y1)) return true;
        if (isInCircle(radius, x_center, y_center, x1, y2)) return true;
        if (isInCircle(radius, x_center, y_center, x2, y1)) return true;
        if (isInCircle(radius, x_center, y_center, x2, y2)) return true;
        if (x_center >= x1 && x_center <= x2) {
            if (abs(y1 - y_center) <= radius) return true;
            if (abs(y2 - y_center) <= radius) return true;
        }
        if (y_center >= y1 && y_center <= y2) {
            if (abs(x1 - x_center) <= radius) return true;
            if (abs(x2 - x_center) <= radius) return true;
        }
        return false;
    }

    bool isInCircle(int radius, int x_center, int y_center, int x1, int y1) {
        return (x_center - x1) * (x_center - x1) + (y_center - y1) * (y_center - y1) <= radius * radius;
    }
};

int main() {
    Solution a;
    cout << a.checkOverlap(1,0,0,1,-1,3,1) << endl;
    cout << a.checkOverlap(24,13,1,0,15,5,18) << endl;
    return 0;
}
