class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int count = 0;
        int ans = 0;

        int   n = mat.size();
        for(int i=0;i<n;i++){
            int temp = 0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 1) temp++;
            }
            if(temp>count){
                count = temp;
                ans = i;
            }
        }
        return {ans,count};
    }
};