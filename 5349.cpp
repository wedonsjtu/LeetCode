#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        if (reservedSeats.empty()) return n * 2;
        vector<array<bool, 10>> v;
        unordered_map<int, int> hashmap;
        int index = 0, ans=0;
        for (int i=0; i < reservedSeats.size(); ++i) {
            int r = reservedSeats[i][0]-1, c = reservedSeats[i][1]-1;
            if (hashmap.find(r) == hashmap.end()) {
                hashmap.insert({r, index});
                v.push_back(array<bool, 10>());
                v[index][c] = true;
                index++;
            }
            else {
                v[hashmap[r]][c] = true;
            }
        }
        for (int i=0; i < index; ++i) {
            auto& seat = v[i];
            if (!seat[2] && !seat[3] && !seat[4] && !seat[1]) {
                ans++;
                if (!seat[6] && !seat[7] && !seat[8] && !seat[5]) ans++;
                continue;
            }
            if (!seat[6] && !seat[3] && !seat[4] && !seat[5]) {ans++; continue;}
            if (!seat[6] && !seat[7] && !seat[8] && !seat[5]) ans++;
        }
        return ans + (n - index) * 2;
    }
};
