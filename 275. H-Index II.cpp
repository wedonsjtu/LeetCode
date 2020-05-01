#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int begin = 0, end = citations.size() - 1;
        int len = citations.size();
        int mid;
        while (begin <= end) {
            mid = begin + (end - begin) / 2;
            if(citations[mid] == len - mid) return citations[mid];
            if (citations[mid] > len - mid) end = mid - 1;
            else begin = mid + 1;
        }
        return len - begin;
    }
};

int main() {
    vector<int> v{0,1,3,5,6};
    cout << Solution().hIndex(v) << endl;
    return 0;
}
