class Twitter {
    int time;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int,int>>> tweets;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto tweet :tweets[userId]) {
            pq.push(tweet);
        }
        if(followers.find(userId) != followers.end()) {
            for(int followeeId :  followers[userId]) {
                for(auto & tweet : tweets[followeeId]) {
                    pq.push(tweet);
                }
            }
        }

        vector<int> results;
        int count  = 0;
        while(!pq.empty() && count < 10) {
            results.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return results;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followers.find(followerId) != followers.end()) {
            followers[followerId].erase(followeeId);
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