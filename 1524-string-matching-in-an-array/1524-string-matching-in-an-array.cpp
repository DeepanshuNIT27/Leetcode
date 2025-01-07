class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>s;
        for(int i=0 ;i< words.size();i++){
            auto st = words[i];
            for(int j=0 ;j<words.size();j++){
                auto st1 = words[j];
                if(i==j){
                    continue;
                }
                if(st1.find(st)!=-1){
                    s.push_back(st);
                    break;
                }
            }
        }
        return s;
    }
};