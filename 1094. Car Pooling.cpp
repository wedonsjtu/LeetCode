#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if (trips.size() == 0) return true;
		int now_passengers_size = 0;
		int i = 0;
		for (i=0; i < trips.size(); ++i) {
			now_passengers_size = max(now_passengers_size, trips[i][2]);
		}
		int* now_passengers = new int[now_passengers_size+1]();
		for (i=0; i < trips.size(); ++i) {
			now_passengers[trips[i][1]] += trips[i][0];
			now_passengers[trips[i][2]] -= trips[i][0];
		}
		for (i=0; i < now_passengers_size + 1; ++i) {
			capacity -= now_passengers[i];
			if (capacity < 0) {
				delete[] now_passengers;
				return false;
			}
		}
		delete[] now_passengers;
		return true;
    }
};

int main() {
	Solution a;
	vector<vector<int>> trips = {vector<int>{2,1,5},vector<int>{3,3,7}};
	cout << a.carPooling(trips, 4) << endl;
	return 0;
}
