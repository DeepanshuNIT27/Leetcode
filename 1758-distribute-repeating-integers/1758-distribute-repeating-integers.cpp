class Solution {
public:
bool canDistributeHelper(vector<int>&count,vector<int>& quantity,int indexcust){
    //BASE CASE
    if(indexcust >= quantity.size()){
        return true;
    }

    for(int i=0;i<count.size();i++){
        if(count[i]>=quantity[indexcust]){
            count[i] -= quantity[indexcust];
            if(canDistributeHelper(count,quantity,indexcust+1)){
                return true;
            }
            count[i] += quantity[indexcust];
        }
    }
    return false;
}
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    unordered_map<int,int>mpcount;
    for(auto&num:nums) mpcount[num]++;
    vector<int>count;
    for(auto&it:mpcount) count.push_back(it.second);
    sort(quantity.rbegin(),quantity.rend());
      return  canDistributeHelper(count,quantity,0);
    }
};