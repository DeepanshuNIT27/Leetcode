class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int>ans;
        map<int,vector<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        //map traverse
        bool flag = true;
        for(auto &it:mp){
            if(flag){
                reverse(it.second.begin(),it.second.end());
            }
            for(auto i :it.second){
                ans.push_back(i);
            }
            flag = !flag;
                    }
        return ans;
    }
};