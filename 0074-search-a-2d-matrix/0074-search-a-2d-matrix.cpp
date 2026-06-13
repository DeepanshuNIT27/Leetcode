class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int s  = 0;
        int e = matrix.size()-1;
        int m = matrix[0].size();

        while(s<=e){

            int mid =  s + (e-s)/2;

            if(matrix[mid][0]<= target && target<= matrix[mid][m-1]){

                for(int i=0;i<m;i++){
                    if(matrix[mid][i] == target) return true;
                }
            }

            if( target <matrix[mid][0]) {
                 e = mid-1;
            }
            else{
                 s = mid+1;
            }
        }
        return false;

    }
};