class Solution {
public:
bool solve(vector<vector<int>>& matrix,int target,int index , int &n){
    //base case
    if(index>=matrix.size()){
        return false;
    }
    //1 case hm dekhenge 

    for(int i=0;i<n;i++){
     if(matrix[index][i]>target){
         n = i;
         break;
     }
     else if(matrix[index][i]==target){
        n = 0;
       return true;
     }
    }

    int ans =   solve(matrix,target,index+1,n);
    return ans;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int index = 0;
     return  solve(matrix,target,index,n);
    
        
    }
};