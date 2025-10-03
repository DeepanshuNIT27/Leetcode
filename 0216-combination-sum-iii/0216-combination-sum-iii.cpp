class Solution {
public:
void solve(vector<vector<int>>&ans,vector<int>&temp,int target , int index,int k){
    if(target<0) return ;
    if(target==0 && temp.size()==k){
        ans.push_back(temp);
        return ;
    }
    for(int i= index;i<=9;i++){
        temp.push_back(i);
        solve(ans,temp,target-i,i+1,k);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,n,1,k);
        return ans;
    }
};