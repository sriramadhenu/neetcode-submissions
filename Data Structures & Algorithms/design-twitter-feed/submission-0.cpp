class Twitter {
private:
    unordered_map<int, unordered_set<int>> following; // {userID, set of who this user is following}
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;  // {tweetTime, tweetID}

public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // min-heap on time: top is the oldest of the kept tweets
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        auto addTweets = [&](int user) {
            for (auto& t : tweets[user]) {
                pq.push(t);
                if (pq.size() > 10) pq.pop();   // drop the oldest
            }
        };

        addTweets(userId);                       // your own tweets
        for (int f : following[userId]) addTweets(f);

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end());   // heap gave oldest first, we want newest first
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
