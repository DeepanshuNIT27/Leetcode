class Twitter {
// REVISION ME ACHHE SE TRY KRNA TRICKY HAI THODA YE 
private:
   int time = 0;
   unordered_map<int,unordered_set<int>>followMap;
   unordered_map<int,vector<pair<int,int>>>tweets;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;

        //self include
        followMap[userId].insert(userId);

        priority_queue<tuple<int,int,int,int>>pq;
        // { time,tweetId, userId,index}

        for(int uid : followMap[userId]){
            auto&v = tweets[uid];
            if(!v.empty()){
                int idx  = v.size() - 1;
                pq.push({v[idx].first ,v[idx].second , uid, idx});
            }
        }
        while(!pq.empty() && res.size()<10){
            auto[t,tweetId,uid,idx] = pq.top();
            pq.pop();

            res.push_back(tweetId);
            if(idx>0){
                idx--;
                pq.push({tweets[uid][idx].first,
                        tweets[uid][idx].second,
                        uid,
                        idx});
            }
        }
        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
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