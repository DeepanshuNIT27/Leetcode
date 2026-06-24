class Solution {
public:

void solveRec(int i, int sum , int k , int n , vector<int>&temp, vector<vector<int>>&ans ){

     if(sum == n) {
        if(temp.size() == k) {
            ans.push_back(temp);
            
        }
        return;
     }
    if (sum > n || temp.size() > k) return;
     for(int j=i;j<=9;j++){
        if(sum + j > n) break;

        temp.push_back(j);
        solveRec(j+1,sum+j,k,n,temp,ans);
        temp.pop_back();
     }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;

        solveRec(1,0,k,n,temp,ans);
        return ans;
    }
};