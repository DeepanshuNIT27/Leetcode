class Solution {
public:
//THIS IS MY FIRST APPROACH (26*M+N) COMPLEXITY
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(auto&it:t) mp2[it]++;

        int i = 0;
        int j = 0;
        int n = s.size();
        int start = 0;
        int minlength = INT_MAX;

        while(j<n){

            mp1[s[j]]++;

            while(i<=j){
                bool flag = true;
                for(auto&it:mp2){
                    if(it.second>mp1[it.first]){
                        flag = false ;
                        break;
                    }
                }
                if(!flag) break;
                if(j-i+1 < minlength){
                    start = i;
                    minlength = j-i+1;
                }
              if(mp1[s[i]]==1) mp1.erase(s[i]);
              else mp1[s[i]]--;
              i++;

            }
            j++;
        }
        if(minlength==INT_MAX) return "";
return s.substr(start,minlength);
    }
};