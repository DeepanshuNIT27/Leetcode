class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        pair<int,int>p;
        int count =0;
        set<pair<int,int>>s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = (abs)(nums[i]-nums[j]);
                if(d==k){
                    p.first =nums[i];
                    p.second=nums[j];
                    s.insert(p);
                    //cout<<p.first<<" "<<p.second<<endl;
                }
            }
        }
        // for(int i=0;i<s.size();i++){
        //     count++;
        // }
        
        return s.size();
    }
};