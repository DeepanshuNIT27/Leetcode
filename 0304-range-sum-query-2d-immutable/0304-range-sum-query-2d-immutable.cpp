class NumMatrix {
public:
 vector<vector<int>>presum;
    NumMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        presum.resize(n+1 , vector<int>(m+1,0));

      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            presum[i][j] = presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1] + matrix[i-1][j-1];
        }
      }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++ ; col1++; row2++ ; col2++;
        int sum = presum[row2][col2] 
                 - presum[row1-1][col2] 
                 - presum[row2][col1-1] 
                 + presum[row1-1][col1-1];
    
    return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */