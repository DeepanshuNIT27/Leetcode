class Solution {
public:
void solve(vector<vector<int>>& matrix,int target,int index , int &n, bool &ans){
    //base case
    if(index>=matrix.size()){
        return ;
    }
    //1 case hm dekhenge 

    for(int i=0;i<n;i++){
     if(matrix[index][i]>target){
         n = i;
         break;
     }
     else if(matrix[index][i]==target){
        ans = true;
        n = 0;
        break;
     }
    }

      solve(matrix,target,index+1,n,ans);
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int index = 0;
        bool ans = false;
       solve(matrix,target,index,n,ans);
       return ans;
        
    }
};