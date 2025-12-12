class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto&it:stones) pq.push(it);
        while(pq.size()>1){
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();

            if(a!=b) pq.push(a-b);
        }
        if(!(pq.empty())) return pq.top();
        return 0;
    }
};