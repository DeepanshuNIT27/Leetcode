class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>>q;
        int freshOrange  = 0;
        // step 1 : rotten orange ko dalo q me vo level 1 hai
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1) freshOrange++;
            }
        }
        if(!freshOrange) return 0;
        int minute = 0;
        vector<pair<int,int>>direction = {{0,1},{1,0},{0,-1},{-1,0}};
        //BFS LOGIC
        while(!q.empty()){
            int size = q.size();
            bool rottennew= false;

            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();

                for(auto j:direction){
                    int newRow = j.first+curr.first;
                    int newCol = j.second + curr.second;
                    if(newRow>=0 && newRow<row && newCol>=0 && newCol<col && grid[newRow][newCol]==1){
                        // new fresh mila rotten kr do
                        grid[newRow][newCol] = 2;
                        freshOrange--;
                        rottennew = true;
                        q.push({newRow,newCol});// next level
                    }
                }

            }
            if(rottennew) minute++;
        }
        if(freshOrange>0) return -1;
        return minute;
    }
};