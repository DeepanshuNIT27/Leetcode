class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //Adjlist
        unordered_map<int,list<pair<int,int>>>Adj;
        for(auto road : roads){
            Adj[road[0]].push_back({road[1],road[2]});
            Adj[road[1]].push_back({road[0],road[2]});
        }

        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>>pq;
     vector<long long >distance(n,LLONG_MAX);
     vector<long long>ways(n,0);

        ways[0] = 1;
        distance[0] = 0;
        pq.push({0,0});
        int mod = 1e9 + 7 ;
        while(!pq.empty()){
            long long cost = pq.top().first;
            long long node = pq.top().second;

            pq.pop();
            for(auto nbr : Adj[node]){
                long long edw = nbr.second;
                long long  AdjNode = nbr.first ;

                if(cost + edw <distance[AdjNode]){
                    distance[AdjNode] = cost + edw;
                    pq.push({distance[AdjNode],AdjNode});
                    ways[AdjNode] = ways[node];
        
                }

                else if(cost + edw == distance[AdjNode]){
                    ways[AdjNode] =  ( ways[AdjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1] % mod ;
    }
};