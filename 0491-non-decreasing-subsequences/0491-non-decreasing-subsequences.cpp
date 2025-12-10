class Solution {
public:
void solve(vector<int>& nums,int index , int prev , vector<int>&temp, set<vector<int>>&st  ){
    if(temp.size()>=2) st.insert(temp); 
    if(index>=nums.size()) return ;

    //include
    if(nums[index]>=prev){
    temp.push_back(nums[index]);
    solve(nums,index+1,nums[index],temp,st);
    temp.pop_back();
    }
    //exclude
    solve(nums,index+1,prev,temp,st);

    
}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
            set<vector<int>>st;
            vector<vector<int>>v;
            vector<int>temp;
            int index = 0;
            solve(nums,index,INT_MIN,temp,st);
            for(auto&it:st) v.push_back(it);
            return v;

    }
};