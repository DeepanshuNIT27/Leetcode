class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Floyd matrix
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                if(i==j) dist[i][j] = 0;
            }
        }
        for(auto edge : edges){
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        for(int h=0;h<n;h++){
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][h]!=INT_MAX && dist[h][j]!=INT_MAX){
                    dist[i][j] = min(dist[i][j],dist[i][h] + dist[h][j]);
                }
            }
          }
        }

        int node = INT_MAX;
        int ans ;
        for(int i=0;i<n;i++){
         int count = 0;
         for(int j=0;j<n;j++){
            if(i==j) continue;
            if(dist[i][j]<=distanceThreshold) count++;
         }
         if(count<=node) {
            ans = i;
            node = count;
         }
        }
        return ans;
    }
};