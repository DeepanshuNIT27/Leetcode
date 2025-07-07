class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int day = 1;
        int  ans = 0;
        int maxday = 0;
        for(auto event:events)  maxday = max(maxday,event[1]);
        int i =0;
        while(day<=maxday){
            //adding starting day 
            while(i<n && events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }
            // removeing expere ans
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
            // event enjoy kro
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
            day++;
        }
        return ans;
    }
};
