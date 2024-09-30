class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        int n = s.length();
        for(int i =0 ; i<n;i++){
            char currentelement=s[i];
            if(ans.empty()){
                ans.push_back(s[i]);
            }
            else if(currentelement==ans.back()){
                ans.pop_back();
            }
            else if ( currentelement!=ans.back()){
                ans.push_back(s[i]);
            }
        }
        
       return ans;
    }
};