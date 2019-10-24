#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.size() <= 1) return true;
		if (rooms[0].empty()) return false;
		unordered_set<int> keys, opened_rooms;
		int now_key;
		keys.insert(0);
		while (!keys.empty()) {
			now_key = *keys.begin();
			keys.erase(now_key);
			opened_rooms.insert(now_key);
			if (opened_rooms.size() == rooms.size()) return true;
			for (int i: rooms[now_key]) {
				if (opened_rooms.count(i) == 0) keys.insert(i);
			}
		}
		return false;
    }
};

int main() {
	Solution a;
	vector<vector<int>> v{vector<int>({1,3}), vector<int>({3,0,1}), vector<int>({2}), vector<int>({0})}; 
	cout << a.canVisitAllRooms(v) << endl;
	return 0;
}
