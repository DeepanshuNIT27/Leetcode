class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<n ;i++){
            for(int j=0;j<m ;j++){
                mp[grid[i][j]]++;
            }
        }
        int a = -1;
        int b = -1;
        for(int i=1;i<=n*n;i++){
            auto it = mp.find(i);
            if(it!=mp.end() && (it->second==2)){
                a = i;
            }
           else if(it==mp.end()){
                b = i;
            }
            if(a!=-1 && b!=-1){
                break;
            }
           
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};