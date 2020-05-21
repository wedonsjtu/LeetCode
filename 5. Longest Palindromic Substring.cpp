#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        pair<int, int> left_right;
        int maxleft = 0;
        int maxright = 0;
        for (int i=0; i < s.size(); ++i) {
            left_right = expandPalindrome(s, i, i);
            if (maxright - maxleft < left_right.second - left_right.first) {
                maxleft = left_right.first;
                maxright = left_right.second;
            }
            left_right = expandPalindrome(s, i, i+1);
            if (maxright - maxleft < left_right.second - left_right.first) {
                maxleft = left_right.first;
                maxright = left_right.second;
            }
        }
        return s.substr(maxleft, maxright-maxleft+1);
    }

private:
    pair<int, int> expandPalindrome(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left+1, right-1};
    }
};

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if (s.size() <= 1) return s;
//         int max_len = 1, max_begin_index=0, begin_index, tmp_len;
//         for (int i=0; i < s.size(); ++i) {
//             tmp_len = findMaxLengthExpandFromCenter(s, i, begin_index);
//             // cout << i << ' ' << tmp_len << endl;
//             if (tmp_len > max_len) {
//                 max_begin_index = begin_index;
//                 max_len = tmp_len;
//                 }
//         }
//         return s.substr(max_begin_index, max_len);
//     }

// private:
//     int findMaxLengthExpandFromCenter(string s, int center, int &begin_index) {
//         int left = center-1, right = center+1, max_odd, max_even;
//         int odd_begin_index = center, even_begin_index = center;
//         while (left >= 0 && right < s.size() && s[left] == s[right]) {
//             odd_begin_index = left--;
//             right++;
//         }
//         max_odd = right - left - 1;

//         left = center;
//         right = center + 1;
//         while (left >= 0 && right < s.size() && s[left] == s[right]) {
//             even_begin_index = left--;
//             right++;
//         }
//         max_even = right - left - 1;
//         if (max_odd > max_even) {
//             begin_index = odd_begin_index;
//             return max_odd;
//         }
//         else {
//             begin_index = even_begin_index;
//             return max_even;
//         }
//     }
// };

int main() {
    Solution a;
    string s("bdaddddcbbad");
    cout << a.longestPalindrome(s) << endl;
    return 0;
}
