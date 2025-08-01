class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if(numRows>=1){
            ans.push_back({1});
        }  if(numRows>=2){
            ans.push_back({1,1});
        }
        for(int i=2;i<numRows;i++){
            vector<int>temp(i+1,1);
            auto v = ans[i-1];//previous
            for(int j=1;j<i;j++){
                temp[j] = v[j]+v[j-1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};