#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        string ipv4("IPv4"), ipv6("IPv6"), neither("Neither");
        int is4 = 0, is6 = 0;
        for (char ch: IP) {
            if (ch == '.') ++is4;
            else if (ch == ':') ++is6;
            else if (!isHexAlphaNum(ch)) return neither;
        }
        if (is4 == 3 && is6 == 0) return (isIPv4(IP)?ipv4:neither);
        if (is4 == 0 && is6 == 7) return (isIPv6(IP)?ipv6:neither);
        return neither;
    }

private:
    bool isIPv4(string IP) {
        string tmp_str;
        int tmp_int;
        IP.push_back('.');
        for (char ch: IP) {
            if (isNum(ch)) {
                tmp_str.push_back(ch);
            }
            else if (ch == '.') {
                if (tmp_str.empty()) return false;
                if (tmp_str.size() >= 4) return false;
                if (tmp_str[0] == '0' && tmp_str.size() > 1) return false;
                tmp_int = stoi(tmp_str);
                if (tmp_int < 0 || tmp_int > 255) return false;
                tmp_str = "";
            }
            else {  // invalid char
                return false;
            }
        }
        return true;
    }
    
    bool isIPv6(string IP) {
        string tmp_str;
        int tmp_int;
        IP.push_back(':');
        for (char ch: IP) {
            if (isHexAlphaNum(ch)) {
                tmp_str.push_back(ch);
            }
            else if (ch == ':') {
                if (tmp_str.empty()) return false;
                if (tmp_str.size() >= 5) return false;
                tmp_str = "";
            }
            else {  // invalid char
                return false;
            }
        }
        return true;
    }
    
    bool isHexAlphaNum(char ch) {
        return isHexAlpha(ch) || isNum(ch);
    }
    
    bool isHexAlpha(char ch) {
        return ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F');  // NOT A to Z!
    }
    
    bool isNum(char ch) {
        return ('0' <= ch && ch <= '9');
    }
};

int main() {
    Solution sol;
    cout << sol.validIPAddress("172.16.254.1") << endl;
    cout << sol.validIPAddress("172.16.254.01") << endl;
    cout << sol.validIPAddress("2001:db8:85a3:0:0:8A2E:0370:7334") << endl;
    return 0;
}
