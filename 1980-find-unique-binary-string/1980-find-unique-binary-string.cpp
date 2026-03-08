class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st;
        for(auto&num:nums) st.insert(num);
        int n = nums.size();
        string s = "";
        string k = "";
        for(int i=0;i<n;i++) {
            s.push_back('0');
            k.push_back('1');
        }
        if(st.find(s)==st.end()) return s;
        if(st.find(k)==st.end()) return k;
        for(int i=0;i<n;i++){
            string p = s;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                p[j] = '1';
              if(st.find(p)==st.end()) return p ;
            }
        }
        return "0";
    }
};