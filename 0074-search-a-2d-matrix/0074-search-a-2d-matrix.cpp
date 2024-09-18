class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        int s =0;
        int n= row*column;
        int e = n-1;
        int mid = s+(e-s)/2;
        int columns;
        while(s<=e){
            int rowindex =mid/column;
            int columnindex = mid%column;
            if(matrix[rowindex][columnindex]==target){
                return true;
            }
           if(matrix[rowindex][columnindex]<target){
            s = mid+1;
           }
           else{
            e = mid-1;
           }
              mid = s+(e-s)/2;
        }
        return false;
    }
};