class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int s = intervals[0][0];
        int e = intervals[0][1];

        for(int i=1;i<n;i++){
         
         if(intervals[i][0] > e){
             ans.push_back({s,e});
             s = intervals[i][0];
             e = intervals[i][1];
         }
         else{
            s = min(s,intervals[i][0]);
            e = max(e,intervals[i][1]);
         }
        }
        ans.push_back({s,e});
        return ans;
    }
};