class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>>map(n,vector<bool>(m,false));
        for(int i=0 ;i< n; i++){
            int sum = 0;
            for(int j=0 ;j<m ;j++){
                  sum = sum + grid[i][j];
            }
            if(sum>1){
                ans = ans + sum;
                for(int j=0 ;j<m ;j++){
                    map[i][j] = true;
                }
            }
        }
        for(int k=0 ;k<m ;k++){
            int sum = 0;
            for(int l=0 ;l<n ;l++){
                sum = sum + grid[l][k];
            }
            if(sum>1){
                for(int l=0 ;l<n ;l++){
                    if(grid[l][k]==1 && map[l][k]==false){
                        ans++;
                        map[l][k] = true;
                    }

                }
            }
        }
        return ans;
    }
};