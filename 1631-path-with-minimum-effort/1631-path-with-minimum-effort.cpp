class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
         int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
   
        pq.push({0,{0,0}});
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
       distance[0][0] = 0;
      
     // n*m*4 * log(n*m)
        while(!pq.empty()){
            auto front = pq.top();
             int cost = front.first;
             int x = front.second.first;
             int y = front.second.second;

             pq.pop();
             if(x==n-1 && y==m-1) return cost;

             int dx[] = {0,0,-1,1};
             int dy[] = {1,-1,0,0};

             for(int i=0;i<4;i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

             if(newx>=0 && newx<n && newy>=0 && newy<m){     
               int d = max(cost,abs(heights[x][y] - heights[newx][newy]));
               if(d<distance[newx][newy]){
                distance[newx][newy] = d;
                 pq.push({d,{newx,newy}});
               }
              

                }
             }    
        }
        return 0;
    }
};