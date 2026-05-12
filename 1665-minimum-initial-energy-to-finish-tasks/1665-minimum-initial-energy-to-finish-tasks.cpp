class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<pair<int,pair<int,int>>>v;
        for(auto temp : tasks){
            int d = temp[1] - temp[0];
            v.push_back({d,{temp[0],temp[1]}});
        }
        sort(v.rbegin(),v.rend());

       int count = 0;
       int ans = 0;

        for(auto&it:v){
            int actual = it.second.first;
            int minimum = it.second.second;

            if(count<minimum) {
                int k = minimum - count;
                count += k ;
                ans  +=  k ;
            }
             
            count -= actual;

        }
        return ans;
    }
};