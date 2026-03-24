class Solution {
public:
    string maximumXor(string s, string t) {
        string p = "";
        int count0 = 0;
        int count1 = 0;
      for(int i=0;i<t.size();i++){
        if(t[i]=='0') count0++;
        else count1++;
      }

      for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            if(count0>0) {p.push_back('0'); count0--;}
            else {
                p.push_back('1');
                count1--;
            }
        }
        else {
            if(count1>0) {p.push_back('1'); count1--;}
            else {
                p.push_back('0');
                count0--;
            }
        }
      }
      string ans = "";
      for(int i=0;i<s.size();i++){
        if(s[i]==p[i] )ans.push_back('0');
        else ans.push_back('1');
      }
      return ans;
    }
};