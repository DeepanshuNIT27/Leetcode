class Solution {
public:
    vector<string> validStrings(int n) {
        long long N = 1<<n;
        vector<string>ans;

        for(long long  i=0;i<N;i++){

            bitset<32>b(i);
            string p = b.to_string();
            string s = p.substr(32-n);
            bool flag = true;
             long long j = 0;
            while(j<s.size()-1){
                if(s[j] == s[j+1] && s[j]=='0'){
                    flag = false;
                    break;
                }
                j++;
            }
            if(flag){
                ans.push_back(s);
            }
        }
        return ans;
    }
};