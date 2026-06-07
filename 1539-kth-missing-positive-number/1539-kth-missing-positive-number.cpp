class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto&it:arr) mp[it]++;

        int num = 1;
        while(k>0){

            if(mp.find(num)==mp.end()){
                k--;
                if(k==0) return num;
            }
           num++;
        }
        return -1;
    }
};