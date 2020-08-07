#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        if (events.empty()) return 0;
        int ans = 0;
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int event_index = 0;
        int today = 0;
        while (!pq.empty() || event_index < events.size()) {
            if (pq.empty() && event_index < events.size()) {
                today = events[event_index][0];
            }
            else {
                ++today;
            }
            while (event_index < events.size() && events[event_index][0] == today) {
                pq.push(events[event_index][1]);
                ++event_index;
            }
            if (!pq.empty()) {
                pq.pop();
                ++ans;
                while (!pq.empty() && pq.top() == today) {
                    pq.pop();
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> events{{1,2},{2,3},{3,4},{1,2}};
    auto ans = Solution().maxEvents(events);
    cout << ans << endl;
    return 0;
}
