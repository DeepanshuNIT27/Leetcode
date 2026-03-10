class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(int i=0;i<queries.size();i++){
            string word = queries[i];
            for(int j=0;j<dictionary.size();j++){
                string p = dictionary[j];
                int diff = 0;
                for(int k=0;k<word.size();k++){
                    if(word[k]!=p[k]) diff++;
                }
                if(diff<=2) { 
                ans.push_back(word);
                break;
                }
            }
        }
        return ans;
    }
};