class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size(),0));
        map<int,vector<int>>mp;
        map<int,vector<pair<int,int>>>mp1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                mp[i-j].push_back(grid[i][j]);
                mp1[i-j].push_back({i,j});
            }
        }
        for(auto it= mp.begin();it!=mp.end();it++){
            int index = it->first;
            auto temp = it->second;
         if(index<0)   sort(temp.begin(),temp.end());
         else  sort(temp.rbegin(),temp.rend());
            auto pair = mp1[index];
            for(int i=0;i<temp.size();i++){
                auto pair1 = pair[i];
                int k = pair1.first;
                int l = pair1.second;
                ans[k][l] = temp[i];
            }
        }
        return ans;
    }
};