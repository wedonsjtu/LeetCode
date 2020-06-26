#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Twitter {
private:
    class User {
    public:
        // int id;
        unordered_set<int> follows;
        deque<pair<int, int>> tweets;
        
        User(): follows(), tweets() {}
    };
    
    unordered_map<int, User> m;
    int timeId;
    
    void createUser(int id) {
        if (m.find(id) == m.end()) {
            m[id] = User();
        }
    }
    
public:
    /** Initialize your data structure here. */
    Twitter(): m(), timeId(INT_MAX) {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        createUser(userId);
        m[userId].tweets.push_front({timeId, tweetId});
        if (m[userId].tweets.size() > 10) {
            m[userId].tweets.pop_back();
        }
        --timeId;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        pair<int, int> tmp;
        for (auto& pair_: m[userId].tweets) {
            pq.push(pair_);
            if (pq.size() == 10) break;
        }
        for (auto id: m[userId].follows) {
            for (auto& pair_: m[id].tweets) {
                pq.push(pair_);
                if (pq.size() > 10) {
                    tmp = pq.top();
                    pq.pop();
                    if (tmp.first == pair_.first) break;
                }
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            tmp = pq.top();
            pq.pop();
            ans.push_back(tmp.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        createUser(followerId);
        createUser(followeeId);
        if (m[followerId].follows.find(followeeId) == m[followerId].follows.end()) {
            m[followerId].follows.insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        createUser(followerId);
        createUser(followeeId);
        if (m[followerId].follows.find(followeeId) != m[followerId].follows.end()) {
            m[followerId].follows.erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main() {
    vector<int> v;
    Twitter twitter;

    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);

    // User 1's news feed should return a list with 1 tweet id -> [5].
    v = twitter.getNewsFeed(1);
    for (int i: v) cout << i << ' ';
    cout << endl;

    // User 1 follows user 2.
    twitter.follow(1, 2);

    // User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);

    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    v = twitter.getNewsFeed(1);
    for (int i: v) cout << i << ' ';
    cout << endl;

    // User 1 unfollows user 2.
    twitter.unfollow(1, 2);

    // User 1's news feed should return a list with 1 tweet id -> [5],
    // since user 1 is no longer following user 2.
    v = twitter.getNewsFeed(1);
    for (int i: v) cout << i << ' ';
    cout << endl;
    return 0;
}
