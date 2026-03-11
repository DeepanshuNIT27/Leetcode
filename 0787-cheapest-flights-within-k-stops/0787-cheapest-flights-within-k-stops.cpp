class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>>Adj;
        for(auto flight : flights){
            Adj[flight[0]].push_back({flight[1],flight[2]});
        }
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        
        vector<int>distance(n,INT_MAX);
        pq.push({0,{src,0}});
        distance[src] = 0;

        while(!pq.empty()){
            auto front = pq.top();
            int limit =  front.first;
            int node =  front.second.first;
            int cost = front.second.second;

            pq.pop();

            for(auto nbr : Adj[node]){
                if(cost + nbr.second < distance[nbr.first] && limit-1<k){
                    distance[nbr.first] = cost + nbr.second;
                    pq.push({limit+1,{nbr.first, distance[nbr.first]}});
                }
            }
        }
        if(distance[dst]==INT_MAX) return -1;
        return distance[dst];
    }
};