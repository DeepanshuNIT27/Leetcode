class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int count = 0;
            auto s = bank[i];
            for(int j=0;j<m;j++){
                if(s[j]=='1') count++;
            }
            ans.push_back(count);
        }
        int j = 0;
        long long res = 0LL;
       for(int i=1;i<ans.size();i++){
        if(ans[i]!=0){
            res += ans[i]*ans[j];
            j = i;
        }
       }
        return res;
    }
};