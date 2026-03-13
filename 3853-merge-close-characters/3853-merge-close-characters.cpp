class Solution {
public:
    string mergeCharacters(string s, int k) {
        
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
               
                if(s[i]==s[j] && j-i<=k){
                    s.erase(j,1);
                     i = 0;
                     j = 0;
                     
                }
            }
        }
        return s;
    }
};