class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int>v(n);
        for(auto i=0;i<n;i++){
            v[i] = tasks[i][0] + tasks[i][1];
        }
        return *min_element(v.begin(),v.end());
    }
};