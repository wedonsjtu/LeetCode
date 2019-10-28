#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
		queue<bool> q;  // vote_list 'R' TRUE 'D' FALSE
		int people_can_vote[2] = {0, 0};
		int ban_time[2] = {0, 0};
        for (char person: senate) {
			if (person == 'R') {
				people_can_vote[1]++;
				q.push(true);
			}
			else if (person == 'D') {
				people_can_vote[0]++;
				q.push(false);
			}
		}
		bool now;
		while (people_can_vote[0] > 0 && people_can_vote[1] > 0) {
			now = q.front();
			q.pop();
			if  (ban_time[now] > 0) {  // has been banned
				ban_time[now]--;
				people_can_vote[now]--;
			}
			else {
				ban_time[!now]++;
				q.push(now);  // can vote again
			}
		}
		return (people_can_vote[1] > 0?"Radiant":"Dire");
    }
};

int main() {
	Solution a;
	// cout << a.predictPartyVictory("RD") << endl;
	cout << a.predictPartyVictory("RDD") << endl;
	return 0;
}
