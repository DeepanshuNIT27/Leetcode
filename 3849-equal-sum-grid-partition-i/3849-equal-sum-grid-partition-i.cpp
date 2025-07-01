class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long>rowsum;
        vector<long long>colsum;
        for(int i=0;i<n;i++){
            long long sum = 0LL;
            for(int j=0;j<m;j++){
             sum += grid[i][j];
            }
            rowsum.push_back(sum);
        }
         for(int i=0;i<m;i++){
        long long  sum = 0LL;
            for(int j=0;j<n;j++){
             sum += grid[j][i];
            }
            colsum.push_back(sum);
        }
        bool ans = false;
        bool ans2 = false;
        long long maxsumr = accumulate(rowsum.begin(),rowsum.end(),0LL);
        long long maxsumc = accumulate(colsum.begin(),colsum.end(),0LL);
        long long z = 0LL;
        for(int i=0;i<rowsum.size()-1;i++){
            z  += rowsum[i];
            if(z*2==maxsumr){
                ans = true;
                break;
            }
        }
        z = 0LL;
         for(int i=0;i<colsum.size()-1;i++){
            z  += colsum[i];
            if(z*2==maxsumc){
                ans2 = true;
                break;
            }
        }
return ans || ans2;
    }
};