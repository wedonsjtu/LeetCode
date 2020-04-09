#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int p_s = S.size()-1, p_t = T.size()-1;
        int sharp_s = 0, sharp_t = 0;
        char s_ch, t_ch;
        bool s_flag, t_flag;
        while (p_s >= 0 || p_t >= 0) {
            s_flag = false;
            t_flag = false;
            if (p_s < 0) s_flag = true;
            else if (S[p_s] == '#') {
                ++sharp_s;
            }
            else {
                if (sharp_s > 0) --sharp_s;
                else {  // 这个字符是真的字符
                    s_flag = true;
                }
            }
            if (p_t < 0) t_flag = true;
            else if (T[p_t] == '#') {
                ++sharp_t;
            }
            else {
                if (sharp_t > 0) --sharp_t;
                else {  // 这个字符是真的字符
                    t_flag = true;
                }
            }
            if (p_s < 0) s_ch = '\0';
            else s_ch = S[p_s];
            if (p_t < 0) t_ch = '\0';
            else t_ch = T[p_t];
            if (s_flag && t_flag && s_ch != t_ch) return false;
            if (!s_flag) --p_s;
            if (!t_flag) --p_t;
            if (s_flag && t_flag) --p_s, --p_t;
        }
        return true;
    }
};

int main() {
    cout << (Solution().backspaceCompare("a##c", "#a#c")?"true":"false") << endl;
    return 0;
}
