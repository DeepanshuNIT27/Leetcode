class Solution {
public:
 void balance(multiset<long long>& lo, multiset<long long>& hi) {
        if (lo.size() > hi.size() + 1) {
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
        }
        else if (hi.size() > lo.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<long long> lo, hi;
        vector<double>ans;
        for(int i=0;i<nums.size();i++){
        //insertion 
        if(lo.empty() || nums[i]<=*lo.rbegin()){
            lo.insert(nums[i]);
        }
        else {
            hi.insert(nums[i]);
        }
        balance(lo,hi);

        //deletion
        if(i>=k){
            long long out = nums[i-k];
            if(out<=*lo.rbegin()){
                lo.erase(lo.find(out));
            }
            else {
                hi.erase(hi.find(out));
            }
            balance(lo,hi);
        } 


        //compute median 
        if(i>=k-1){
            if(k%2==1) ans.push_back(*lo.rbegin());
            else ans.push_back(((double)*lo.rbegin() + (double)*hi.begin())/2.0);
        }
        }
        return ans;
    }
};